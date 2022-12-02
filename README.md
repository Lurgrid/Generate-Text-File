# Generate Text File


* ## Presentation

	You know all the [Lorem Ipsum](https://www.lipsum.com/) this text in Latin which does not mean anything and which is just used to test a font or a paragraph in a website or even to test programs on strings, unfortunately the [Lorem Ipsum generators](https://loremipsum.io/) are very limited with a few thousand words with often not very long words, then with my simple program, you can generate a text with a database of words given and a number of words, now the only limit is your storage.
	
* ## Compilation

	To compile with the make file you would need to have [GCC](https://gcc.gnu.org/) installed on your pc.

```console
lurgrid@foo:~$ cd ./src/
lurgrid@foo:~/src$ make
gcc -std=c18 -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2 -I./stack/   -c -o main.o main.c
gcc -std=c18 -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2 -I./stack/   -c -o stack.o ./stack/stack.c
gcc main.o stack.o -o main
```

* ## Syntax

	
	Syntax: ./main [FILE_OUT] [FILE_IN] [Number of words] [Number of word in line]

	[FILE_OUT]: The path to the file that will be created with the random words.

	[FILE_IN]: The path to the file of words that will be used to create the file.

	[Number of words]: Max value is [MAX_LONG_INT].
	
* ## Exemple

	Small example with the word database: [word.txt](./word.txt)

```console
lurgrid@SAGBOT:~/src$ ./main ./out.txt ./words.txt 70 10

*** Warning: Word 'pneumonoultramicroscopicsilicov...' cut
--- Info: Number of words in ./words.txt: 466550

lurgrid@SAGBOT:~/src$ cat ./out.txt 

flayed fluorosis mountebankly changeless diabetical foreseason Zeona Berthoud obedient thimblefuls innutritiousness
phyt- bachelorism Catonsville Alcalzar circumventer C.T. PMEG siderostat staybolt amphithecial
whittling pre-employment Nisen consuetude microlepidopteran inshell substantiate Upham patriotship welladay
gun-shyness undunged paleochorology outthrob Dothiorella unconstantly outfaming isomeric mahar nonfollowing
succinimide Delanos perforce balaneutics Ghazali tind counter-pole battleship Prasad bowtell
brand-mark rusty-red semiotical pontificially undiscordantly higgaion coccygomorphic scorpene irremovableness shoddy
roamers shakudo rang Juneberries leukoblastic Anti-Mason guilt chowsed lightsomely

lurgrid@SAGBOT:~/src$ 

```

## Acknowledgments

We thank Mr. C.Hancart for the knowledge used to elaborated this program.