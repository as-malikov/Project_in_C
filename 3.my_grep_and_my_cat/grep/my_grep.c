/**
 * @file my_cat.c
 * @author rzhao (rzhao@student.21-school.ru)
 * @version 0.1
 * @date 2022-02-26
 * @copyright Copyright (c) 2022
 */

#include "./my_grep.h"

int main(int argc, char **argv) {
  my_grep(argc, argv);
  return 0;
}

void my_grep(int argc, char **argv) {
  struct flag flag = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  struct help help = {"", NULL, 0, 0, 0, 0, 0, 0};
  regex_t regex_t;
  readFlag(argc, argv, &flag, &help);
  int cflagsOther = 0;
  if (flag.i) {
    cflagsOther = REG_EXTENDED | REG_ICASE;
  } else {
    cflagsOther = REG_EXTENDED;
  }
  if (!help.boolEF) {
    functionAdd(&help, argv[optind]);
    help.nOptind = optind;
  }
  if (regcomp(&regex_t, help.regularString, cflagsOther)) {
    fprintf(stderr,
            "ERROR, regularString line did not compile: %s\n",
            help.regularString);
  } else {
    help.boolRegCompil = 1;
  }
  printFile(flag, help, argc, argv, regex_t);
}

void readFlag(int argc, char **argv, flag *flag, help *help) {
  int opt;
  while ((opt = getopt(argc, argv, "ievclnhsof")) != -1) {
    switch (opt) {
    case 'i': {
      flag->i++;
      break;
    }
    case 'e': {
      flag->e++;
      help->nOptind = optind++;
      functionAdd(help, argv[(help->nOptind)]);
      help->boolEF++;
      break;
    }
    case 'v': {
      flag->v++;
      break;
    }
    case 'c': {
      flag->c++;
      break;
    }
    case 'l': {
      flag->l++;
      break;
    }
    case 'n': {
      flag->n++;
      break;
    }
    case 'h': {
      flag->h++;
      break;
    }
    case 's': {
      flag->s++;
      break;
    }
    case 'o': {
      flag->o++;
      break;
    }
    case 'f': {
      flag->f++;
      help->nOptind = optind++;
      functionF(help, argv[help->nOptind]);
      break;
    }
    default: {
      flag->boolFlagFail = -1;
    }
    }
  }
}

void functionAdd(help *help, char *argv) {
  int length = strlen(help->regularString);
  if (length) {
    snprintf(help->regularString + length++, SIZE, "|");
  }
  snprintf(help->regularString + length, SIZE, "%s", argv);
}

void printFile(flag flag, help help, int argc, char **argv, regex_t regex_t) {
  help.nOptind++;
  if (help.nOptind == argc) {
    fprintf(stderr, "ERROR, no files\n");
  } else if (!flag.h && help.nOptind < argc - 1) {
    help.chekFile = 1;
  }

  while (help.nOptind < argc) {
    FILE *fileSource;
    if ((fileSource = fopen(argv[help.nOptind++], "r")) == NULL) {
      if (!flag.s) {
        fprintf(stderr,
                "ERROR, grep: %s: No such file or directory\n",
                argv[help.nOptind - 1]);
      }
      continue;
    } else {
      help.pathFile = argv[help.nOptind - 1];
      isPrintFile(fileSource, &flag, &help, regex_t);
      fclose(fileSource);
    }
  }

  if (help.boolRegCompil) {
    regfree(&regex_t);
  }
}

void isPrintFile(FILE *fileSource, flag *flag, help *help, regex_t regex_t) {
  help->count = 0;
  isPrintFileHelp(regex_t, flag, help, fileSource);
  if (flag->c && !flag->l) {
    if (help->chekFile) {
      printf("%s:", help->pathFile);
    }
    printf("%d\n", help->count);
  }
}

void isPrintFileHelp(regex_t regex_t, flag *flag, help *help,
  FILE *fileSource) {
  char *bufferString = malloc(SIZE * sizeof(char));
  help->line = 1;
  while (fgets(bufferString, SIZE, fileSource) != NULL) {
    if (bufferString[strlen(bufferString) - 1] != '\n') {
      if (getLine(&bufferString, fileSource)) {
        break;
      }
    }
    regmatch_t regmatch_t[SIZE];
    int result;
    result = regexec(&regex_t, bufferString, SIZE, regmatch_t, 0);
    if ((!result && !flag->v) || (result == REG_NOMATCH && flag->v)) {
      if (flag->c && !flag->l) {
        help->count++;
      } else {
        if (flag->l) {
          printf("%s\n", help->pathFile);
          break;
        }
        if (help->chekFile) {
          printf("%s:", help->pathFile);
        }
        if (flag->n) {
          printf("%d:", help->line);
        }
        if (flag->o) {
          matched(bufferString, regex_t);
        } else {
          printf("%s", bufferString);
        }
      }
    } else if (result != REG_NOMATCH && result != 0) {
      fprintf(stderr, "Error, REG_NOMATCH\n");
    }
    help->line++;
  }
  free(bufferString);
}

void matched(char *bufferString, regex_t regex_t) {
  int shift = 0;
  regmatch_t regmatch_t[SIZE];
  while (!regexec(&regex_t, &bufferString[shift], SIZE, regmatch_t, 0)) {
    int i = regmatch_t[0].rm_so;
    while (i < regmatch_t[0].rm_eo) {
      printf("%c", bufferString[shift + i]);
      i++;
    }
    printf("\n");
    shift += regmatch_t[0].rm_eo;
  }
}

int getLine(char **bufferString, FILE *fileSource) {
  int size = SIZE, result = 0;
  while ((*bufferString)[strlen(*bufferString) - 1] != '\n') {
    char *tempString = NULL;
    if (((*bufferString) =
        realloc(tempString = (*bufferString), size + SIZE * sizeof(char)))) {
      if (fgets((*bufferString) + size - size / SIZE, SIZE, fileSource) ==
          NULL) {
        break;
      }
    } else {
      free(tempString);
      fprintf(stderr, "Error, allocate memory\n");
      result = 1;
    }
    size += SIZE;
  }
  return result;
}

void functionF(help *help, char *argv) {
  FILE *openFile = fopen(argv, "r");
  if (openFile == NULL) {
    printf("ERROR, grep: %s: No such file or directory\n", argv);
  } else {
    functionFHelp(help, openFile);
    fclose(openFile);
  }
  help->boolEF++;
}

void functionFHelp(help *help, FILE *openFile) {
  char buffer[SIZE] = "";
  while (fgets(buffer, SIZE, openFile) != NULL) {
    int length;
    length = strlen(help->regularString);
    if (length) {
      snprintf(help->regularString + length++, SIZE, "|");
    }
    snprintf(help->regularString + length, SIZE, "%s", buffer);
    length = strlen(help->regularString);
    if (help->regularString[length - 1]
        == '\n' && help->regularString[length - 2] == '\n') {
      length--;
      help->regularString[length] = '\0';
    }
  }
}
