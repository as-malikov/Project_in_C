/**
 * @file my_cat.c
 * @author rzhao (rzhao@student.21-school.ru)
 * @version 0.1
 * @date 2022-02-26
 * @copyright Copyright (c) 2022
 */

/**
 * int * flagsArray[] =
 * [0]='err',
 * [1]='n',
 * [2]='b',
 * [3]='s',
 * [4]='e',
 * [5]='t',
 * [6]='v'

 * int * help[] =
 * [0]=outpurCountLine
 * [1]=countFile
 * [2]=countLineForSChar
 * [3]=bufferChar
 * [4]=EOF
 */

#include "./my_cat.h"

int main(int argc, char **argv) {
    my_cat(argc, argv);
    return 0;
}

void my_cat(int argc, char **argv) {
    int flagsArray[FLAGS_SIZE], helpArray[HELP_SIZE];
    init(flagsArray, FLAGS_SIZE);
    init(helpArray, HELP_SIZE);
    getFlag(argc, argv, flagsArray);
    if (flagsArray[0] == -1) {
        fprintf(stderr, "usage: my_cat [-senbt] [file ...]\n");
    } else {
        for (int i = optind; i < argc; i++) {
            FILE *fileSource = fopen(argv[i], "r");
            if (fileSource == NULL) {
                fprintf(stderr,
                    "my_cat: %s: No such file or directory\n", argv[i]);
                break;
            } else {
                outputText(fileSource, flagsArray, helpArray);
            }
            fclose(fileSource);
        }
    }
}

void init(int *flagsArray, int size) {
    for (int i = 0; i < size; i++) {
        flagsArray[i] = 0;
    }
}

void getFlag(int argc, char **argv, int *flagsArray) {
    int getOption = 0;
    while ((getOption = getopt(argc, argv, "nbset")) != -1) {
        switch (getOption) {
            case 'n': {
                flagsArray[1]++;
                break;
            }
            case 'b': {
                flagsArray[2]++;
                break;
            }
            case 's': {
                flagsArray[3]++;
                break;
            }
            case 'e': {
                flagsArray[4]++;
                flagsArray[6]++;
                break;
            }
            case 't': {
                flagsArray[5]++;
                flagsArray[6]++;
                break;
            }
            default: {
                flagsArray[0] = -1;
            }
        }
    }
}

void outputText(FILE *fileSource, int *flagsArray, int *helpArray) {
    char bufferChar = '\n', getChar;
    if (flagsArray[1] == 'n' && !helpArray[2])
        printf("%6d\t", ++flagsArray[1]);
    do {
        getChar = fgetc(fileSource);
        if (flagsArray[3] && getChar == '\n')
            functionS(&getChar, bufferChar, fileSource, flagsArray, helpArray);
        if ((flagsArray[1] || flagsArray[2]) &&
            !(helpArray[1] && getChar != '\n' && bufferChar == '\0'
                && helpArray[3] != '\n')) {
            functionBN(flagsArray, getChar, bufferChar, helpArray);
        }
        if (getChar == '\n' && flagsArray[4]) {
            printf("$");
        }
        int specChar = getChar;
        if ((flagsArray[5] == 1 && (specChar == 9)) ||
            (flagsArray[6] == 1 && ((specChar >= 0 && specChar < 9)
                || (specChar > 10 && specChar < 32))))
            printf("^%c", specChar + '@');
        else if (getChar != -1)
            printf("%c", getChar);
        bufferChar = getChar;
        helpArray[4] = 0;
        if (getChar != -1) {
            helpArray[3] = bufferChar;
            helpArray[2] = 0;
        }
    } while (getChar != -1);
}

void functionS(char *getChar, char bufferChar,
    FILE *fileSource, int *flagsArray, int *helpArray) {
    if (flagsArray[4]) {
        if (!helpArray[1]) {
            printf("$");
        } else if (bufferChar != '\0') {
            printf("$");
        } else if (helpArray[3] != '\n') {
            printf("$");
        }
    }
    if (((!helpArray[1] || helpArray[2] == 1) && helpArray[3] != '\n')
        || (helpArray[3] != '\n')) {
        printf("%c", *getChar);
    }
    while (*getChar == '\n') {
        helpArray[3] = *getChar;
        *getChar = fgetc(fileSource);
        helpArray[2]++;
    }
    funcSHelp(flagsArray, helpArray, *getChar, bufferChar);
}

void funcSHelp(int *flagsArray, int *helpArray, char getChar, char bufferChar) {
    if (bufferChar == '\0' && helpArray[2] > 1
        && helpArray[1] && !helpArray[4]) {
        if (flagsArray[1]) {
            printf("%6d\t", ++helpArray[0]);
        }
        if (flagsArray[4]) {
            printf("$");
        }
        printf("\n");
    }
    if ((flagsArray[1] || (flagsArray[2] && bufferChar != '\0'
        && (bufferChar == '\n' || helpArray[2] == 1))) &&
        getChar != EOF) {
        printf("%6d\t", ++helpArray[0]);
    }
    if (helpArray[2] > 1 && bufferChar != '\0') {
        if (flagsArray[4]) {
            printf("$");
        }
        printf("\n");
        if (getChar == EOF) {
            helpArray[4] = 1;
        }
        if ((flagsArray[1] || flagsArray[2]) && getChar != EOF) {
            printf("%6d\t", ++helpArray[0]);
        }
    }
}

void functionBN(int *flagsArray, char getChar, char bufChar, int *helpArray) {
    if (flagsArray[1] && bufChar == '\n' && getChar != EOF) {
        printf("%6d\t", ++(helpArray[0]));
        flagsArray[1] = 1;
    }
    if (flagsArray[2] && ((getChar != '\n' && bufChar == '\n')
     || (bufChar == '\0' && getChar != '\n')) &&
        getChar != EOF) {
        printf("%6d\t", ++(helpArray[0]));
    }
}
