//  stack.c : partie implantation d'un module polymorphe pour la spécification
//    PILE du TDA Pile(T).

#include "stack.h"
#include <stdint.h>

//  struct stack, stack : gestion des adresses des objets dans la pile à l'aide
//    d'un tableau a taille dynamique. Le composant aref a pour valeur le
//    pointeur du tableau de ref, le composant height mémorise la longueur de
//    la tableau. Le composant height a donc pour valeur la hauteur de la pile.
//    et capacity a pour valeur la capacité actuel de la pile.

#define DEFAULT_SIZE 32
#define MULTI_STACK 2

struct stack {
  const void **aref;
  size_t height;
  size_t capacity;
};

stack *stack_empty(void) {
  stack *p = malloc(sizeof *p);
  if (p == NULL) {
    return NULL;
  }
  p->aref = malloc(DEFAULT_SIZE * sizeof *(p->aref));
  if (p->aref == NULL) {
    free(p);
    return NULL;
  }
  p->height = 0;
  p->capacity = DEFAULT_SIZE;
  return p;
}

void stack_dispose(stack **sptr) {
  if (*sptr == NULL) {
    return;
  }
  free((*sptr)->aref);
  free(*sptr);
  *sptr = NULL;
}

void *stack_push(stack *s, const void *ref) {
  if (ref == NULL) {
    return NULL;
  }
  if (s->height < s->capacity) {
    s->aref[s->height] = ref;
  } else {
    if (MULTI_STACK > SIZE_MAX / (s->capacity * sizeof *(s->aref))) {
      return NULL;
    }
    const void **t = realloc(s->aref,
        s->capacity * sizeof *(s->aref) * MULTI_STACK);
    if (t == NULL) {
      return NULL;
    }
    s->capacity *= MULTI_STACK;
    s->aref = t;
    s->aref[s->height] = ref;
  }
  ++(s->height);
  return (void *) ref;
}

void *stack_pop(stack *s) {
  if (stack_is_empty(s)) {
    return NULL;
  }
  --s->height;
  return (void *) s->aref[s->height];
}

void *stack_top(stack *s) {
  if (stack_is_empty(s)) {
    return NULL;
  }
  return (void *) s->aref[s->height - 1];
}

void *stack_nth(stack *s, size_t n){
  if (stack_is_empty(s) || n > s->height){
    return NULL;
  }
  return (void *) s->aref[n - 1];
}

bool stack_is_empty(stack *s) {
  return s->height == 0;
}

size_t stack_height(stack *s) {
  return s->height;
}
