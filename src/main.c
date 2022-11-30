#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

#define MAX_LEN 31

#define STR(s) #s
#define XSTR(s) STR(s)

int main(int argc, char **argv) {
  if (argc < 5) {
    fprintf(stderr,
        "*** Syntax: "
        "%s [FILE_OUT] [FILE_IN] [Number of words] [Number of word in line]\n"
        "\n\t[FILE_OUT]: "
        "The path to the file that will be created with the random words.\n"
        "\n\t[FILE_IN]: "
        "The path to the file of words that will be used to create the file.\n",
        argv[0]);
    return EXIT_FAILURE;
  }
  int a;
  int b;
  if (sscanf(argv[3], "%d", &a) != 1 || a <= 0
      || sscanf(argv[4], "%d", &b) != 1 || b <= 0) {
    fprintf(stderr, "*** Error: Please enter a positive non-zero integer.\n");
    return EXIT_FAILURE;
  }
  size_t nb_w = (size_t) a;
  size_t width = (size_t) b;
  FILE *in = fopen(argv[2], "r");
  if (in == NULL) {
    fprintf(stderr, "*** Error: Cannot open the %s file.\n", argv[2]);
    return EXIT_FAILURE;
  }
  FILE *out = fopen(argv[1], "wx");
  if (out == NULL) {
    if (fclose(in) != 0) {
      fprintf(stderr, "*** Error: Cannot close the %s file.\n", argv[2]);
    }
    fprintf(stderr, "*** Error: File %s already exists.\n", argv[1]);
    return EXIT_FAILURE;
  }
  int r = EXIT_SUCCESS;
  stack *s = stack_empty();
  if (s == NULL) {
    goto error;
  }
  char w[MAX_LEN + 1];
  while (fscanf(in, "%" XSTR(MAX_LEN) "s", w) != EOF) {
    int c = fgetc(in);
    if (c != EOF && !isspace(c)) {
      fprintf(stderr, "*** Warning: Word '%s...' cut\n", w);
      do {
        c = fgetc(in);
      } while (c != EOF && !isspace(c));
    }
    char *t = malloc(strlen(w) + 1);
    if (t == NULL) {
      fprintf(stderr, "*** Error: No more memory space available.\n");
      goto error;
    }
    strcpy(t, w);
    if (stack_push(s, t) == NULL) {
      free(t);
      fprintf(stderr,
          "*** Error: No more memory space available in the mset.\n");
      goto error;
    }
  }
  if (!feof(in)) {
    fprintf(stderr,
        "*** Error: An error occurred during the reading on the file %s.\n",
        argv[2]);
    goto error;
  }
  if (stack_is_empty(s)) {
    fprintf(stderr, "***Error: Empty %s file.\n", argv[2]);
    goto error;
  }
  fprintf(stderr,
      "--- Info: Number of words in %s: %ld\n", argv[2], stack_height(s));
  size_t k = 1;
  while (k <= nb_w
      && fprintf(out, "%s",
      (char *) stack_nth(s, (size_t) rand() % stack_height(s) + 1)) != EOF
      && fputc(k % width == 0 ? '\n' : ' ', out) != EOF) {
    ++k;
  }
  goto clear;
error:
  r = EXIT_FAILURE;
  goto clear;
clear:
  while (!stack_is_empty(s)) {
    char *t = stack_pop(s);
    free(t);
  }
  goto dispose;
dispose:
  stack_dispose(&s);
  goto close;
close:
  if (fclose(in) != 0) {
    r = EXIT_FAILURE;
    fprintf(stderr, "*** Error: Cannot close the %s file.\n", argv[2]);
  }
  if (fclose(out) != 0) {
    r = EXIT_FAILURE;
    fprintf(stderr, "*** Error: Cannot close the %s file.\n", argv[1]);
  }
  return r;
}
