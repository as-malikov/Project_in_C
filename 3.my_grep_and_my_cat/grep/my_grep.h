#ifndef SRC_my_GREP_H
#define SRC_my_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

typedef struct flag {
    int i;
    int e;
    int v;
    int c;
    int l;
    int n;
    int h;
    int s;
    int f;
    int o;
    int boolFlagFail;
} flag;

typedef struct help {
    char regularString[SIZE];
    char *pathFile;
    int chekFile;
    int boolEF;
    int boolRegCompil;
    int nOptind;
    int line;
    int count;
} help;

void my_grep(int argc, char **argv);

void readFlag(int argc, char **argv, flag *flag, help *help);

void functionAdd(help *help, char *argv);

void functionF(help *help, char *argv);

void matched(char *buf, regex_t regex);

void functionFHelp(help *help, FILE *openFile);

void printFile(flag flag, help help, int argc, char **argv, regex_t regex_t);

void isPrintFile(FILE *fileSource, flag *flags, help *help, regex_t regex_t);

void isPrintFileHelp(regex_t regex_t, flag *flag, help *help, FILE *fileSource);

int getLine(char **buf, FILE *fileSource);

#endif 