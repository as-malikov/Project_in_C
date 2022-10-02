#ifndef my_CAT_H_
#define my_CAT_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
 
#define FLAGS_SIZE 7
#define HELP_SIZE 5

void my_cat(int argc, char **pString);

void init(int *flagsArray, int size);

void getFlag(int argc, char **argv, int *flagsArray);

void outputText(FILE *fileSource, int *flagsArray, int *helpArray);

void functionS(char *getChar, char bufferChar, FILE *fileSource, int *flagsArray, int *helpArray);

void funcSHelp(int *flagsArray, int *helpArray, char getChar, char bufChar);

void functionBN(int *flagsArray, char getChar, char bufChar, int *helpArray);

#endif