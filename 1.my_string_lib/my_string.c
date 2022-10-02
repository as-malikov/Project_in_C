#include "my_string.h"

#if defined(unix) || defined(__unix__) || defined(__unix)
#define MAXERROR 134
const char *const errorMessage[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error",
    "Unknown error"
};

#endif

#if defined(__APPLE__) || defined(__MACH__)
#define MAXERROR 107
const char *const errorMessage[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full",
    "Unknown error:"
};

#endif

#define INT_FLAG 0
#define SHORT_INT_FLAG 1
#define LONG_INT_FLAG 2
#define UNSIGNED_INT_FLAG 3
#define UNSIGNED_SHORT_INT_FLAG 4
#define UNSIGNED_LONG_INT_FLAG 5
#define DOUBLE_FLAG 6
#define STRING_FLAG 7

/*---------------------------------------------
            FUNCTION my_MEMCHR
   Searches for the first occurrence of
   the character c (an unsigned char)
   in the first n bytes of the string
   pointed to, by the argument str.
 --------------------------------------------*/
void *my_memchr(const void *str, int c, my_size_t n) {
    const char *foundSymbol = my_NULL;
    const char *string = (const char *)str;
    for (my_size_t indexSymbol = 0; indexSymbol < n; indexSymbol++) {
        if (string[indexSymbol] == c) {
            foundSymbol = &string[indexSymbol];
            break;
        }
    }
    return (void*)foundSymbol;
}

/*---------------------------------------------
            FUNCTION my_MEMCMP
   Compares the first n bytes of str1
   and str2.
 --------------------------------------------*/
int my_memcmp(const void *str1, const void *str2, my_size_t n) {
    if (n != 0) {
        const unsigned char *string1 = str1;
        const unsigned char *string2 = str2;
        int indexSymbol = 0;
        for (indexSymbol = 0; indexSymbol < n; indexSymbol++) {
            if (string1[indexSymbol] != string2[indexSymbol]) {
                break;
            }
        }
        return string1[indexSymbol] - string2[indexSymbol];
    }
    return 0;
}

/*---------------------------------------------
            FUNCTION my_MEMCPY
   Copies n characters from src to dest.
 --------------------------------------------*/
void *my_memcpy(void *dest, const void *src, my_size_t n) {
    char *destanationArray = (char *)dest;
    const char *sourceData = (const char *)src;
    for (my_size_t indexSymbol = 0; indexSymbol < n; indexSymbol++) {
        destanationArray[indexSymbol] = sourceData[indexSymbol];
    }
    return (void *) destanationArray;
}

/*---------------------------------------------
            FUNCTION my_MEMMOVE
   Another function to copy n characters
   from str2 to str1.
 --------------------------------------------*/
void *my_memmove(void *dest, const void *src, my_size_t n) {
    char *destanationArray = (char *)dest;
    const char *sourceData = (char *)src;
    if (sourceData > destanationArray) {
        my_memcpy(destanationArray, sourceData, n);
    } else {
        for (my_size_t indexSymbol = 0; indexSymbol != n; indexSymbol++) {
            destanationArray[n - indexSymbol - 1] = sourceData[n - indexSymbol - 1];
        }
    }
    return (void *) destanationArray;
}

/*---------------------------------------------
            FUNCTION my_MEMSET
    Copies the character c (an unsigned char)
    to the first n characters of the
    string pointed to, by the argument str.
 --------------------------------------------*/
void *my_memset(void *str, int c, my_size_t n) {
    char *string = (char *)str;
    unsigned int symbol = c;
    for (my_size_t indexSymbol = 0; indexSymbol < n; indexSymbol++) {
        string[indexSymbol] = symbol;
    }
    return (void *) string;
}

/*---------------------------------------------
            FUNCTION my_STRCAT
   Appends the string pointed to,
   by src to the end of the string pointed
   to by dest.
 --------------------------------------------*/
char *my_strcat(char *dest, const char *src) {
    char *resultString = dest;
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return resultString;
}

/*---------------------------------------------
            FUNCTION my_STRNCAT
    Appends the string pointed to, by src to
    the end of the string pointed to,
    by dest up to n characters long.
 --------------------------------------------*/
char *my_strncat(char *dest, const char *src, my_size_t n) {
    if (n != 0) {
        char *copyDest = dest;
        const char *copySrc = src;
        while (*copyDest != 0) {
            copyDest++;
        }
        do {
            if ((*copyDest = *copySrc++) == 0) {
                break;
            }
            copyDest++;
        } while (--n != 0);
        *copyDest = 0;
    }
    return dest;
}

/*---------------------------------------------
            FUNCTION my_STRCHR
   Searches for the first occurrence of the
   character c (an unsigned char) in the
   string pointed to, by the argument str.
 --------------------------------------------*/
char *my_strchr(const char *str, int c) {
    const char *foundSymbol = my_NULL;
    for (int indexSymbol = 0; indexSymbol < my_strlen(str)+1; indexSymbol++) {
        if (str[indexSymbol] == c) {
            foundSymbol = &str[indexSymbol];
            break;
        }
    }
    return (char *)foundSymbol;
}

/*---------------------------------------------
            FUNCTION my_STRCMP
   Compares the string pointed to,
   by str1 to the string pointed to
   by str2.
 --------------------------------------------*/
int my_strcmp(const char *str1, const char *str2) {
    int symbol = 0;
    for ( symbol = 0; str1[symbol] == str2[symbol]; symbol++ ) {
        if (str1[symbol] == '\0') {
            break;
        }
    }
    return str1[symbol] - str2[symbol];
}

/*---------------------------------------------
            FUNCTION my_STRNCMP
   Compares at most the first n bytes
   of str1 and str2.
 --------------------------------------------*/
int my_strncmp(const char *str1, const char *str2, my_size_t n) {
    int resultOfComparison = 0;
    for ( my_size_t symbol = 0; symbol < n; symbol++ ) {
        if ( *str1 == *str2 ) {
            str1++;
            str2++;
        } else {
            resultOfComparison = *str1 - *str2;
            break;
        }
    }
    return resultOfComparison;
}

/*---------------------------------------------
            FUNCTION my_STRCPY
   Copies the string pointed to, by
   src to dest.
 --------------------------------------------*/
char *my_strcpy(char *dest, const char *src) {
    char *copyDest = dest;
    while ( *src != '\0' ) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return copyDest;
}

/*---------------------------------------------
            FUNCTION my_STRNCPY
   Copies up to n characters from the
   string pointed to, by src to dest.
 --------------------------------------------*/
char *my_strncpy(char *dest, const char *src, my_size_t n) {
    if (n != 0) {
        char *copyDest = dest;
        const char *copySrc = src;
        do {
            if ((*copyDest++ = *copySrc++) == 0) {
                while (--n != 0) {
                    *copyDest++ = 0;
                }
                break;
            }
        } while (--n != 0);
    }
    return dest;
}

/*---------------------------------------------
            FUNCTION my_STRCSPN
   Calculates the length of the initial
   segment of str1 which consists entirely
   of characters not in str2.
 --------------------------------------------*/
my_size_t my_strcspn(const char *str1, const char *str2) {
    my_size_t calculatedLenght = 0;
    for ( calculatedLenght = 0; str1[ calculatedLenght ] != '\0'; calculatedLenght++ ) {
        for ( int Symbol = 0; str2[ Symbol ] != '\0'; Symbol++ ) {
            if ( str2[ Symbol ] ==  str1[ calculatedLenght ] ) {
                return calculatedLenght;
            }
        }
    }
    return calculatedLenght;
}

/*---------------------------------------------
            FUNCTION my_STRLEN
    Computes the length of the string
    str up to but not including the
    terminating my_NULL character.
 --------------------------------------------*/
my_size_t my_strlen(const char *str) {
    my_size_t stringLenght = 0;
    while (*str++ != '\0') {
        stringLenght++;
    }
    return stringLenght;
}

/*---------------------------------------------
            FUNCTION my_STRPBRK
    Finds the first character in the
    string str1 that matches any
    character specified in str2.
 --------------------------------------------*/
char *my_strpbrk(const char *str1, const char *str2) {
    const char *foundSymbol = my_NULL;
    while (*str1 != '\0') {
        for ( int indexSymbol = 0; str2[ indexSymbol ] != '\0'; indexSymbol++ ) {
            if ( str2[ indexSymbol ] ==  *str1 ) {
                foundSymbol = str1;
                return (char *)foundSymbol;
            }
        }
        str1++;
    }
    return (char*)foundSymbol;
}

/*---------------------------------------------
            FUNCTION my_STRRCHR
    Searches for the last occurrence
    of the character c (an unsigned char)
    in the string pointed to by the
    argument str.
 --------------------------------------------*/
char *my_strrchr(const char *str, int c) {
    const char *foundSymbol = my_NULL;
    for (int indexSymbol = my_strlen(str); indexSymbol >=0; indexSymbol--) {
        if (str[indexSymbol] == c) {
            foundSymbol = &str[indexSymbol];
            break;
        }
    }
    return (char *)foundSymbol;
}

/*---------------------------------------------
            FUNCTION my_STRSTR
    Finds the first occurrence of the
    entire string needle (not including
    the terminating my_NULL character) which
    appears in the string haystack.
 --------------------------------------------*/
char *my_strstr(const char *haystack, const char *needle) {
    const char *copyHaystack = haystack;
    const char *copyNeedle = needle;
    while (1) {
        if (!*copyNeedle) {
            return (char *) haystack;
        } else if (!*copyHaystack) {
            return my_NULL;
        } else if (*copyHaystack++ != *copyNeedle++) {
            copyHaystack = ++haystack;
            copyNeedle = needle;
        }
    }
}

/*---------------------------------------------
            FUNCTION my_STRSPN
    Calculates the length of the initial
    segment of str1 which consists entirely
    of characters in str2.
 --------------------------------------------*/
my_size_t my_strspn(const char *str1, const char *str2) {
    my_size_t lenghSubstring = 0;
    const char *copyStr2 = my_NULL;
    if (str1 == my_NULL) {
        return lenghSubstring;
    }
    for (lenghSubstring = 0; *str1; str1++, lenghSubstring++) {
        for (copyStr2 = str2; *copyStr2 && *copyStr2 != *str1; copyStr2++) {
        }
        if (!*copyStr2) {
            break;
        }
    }
    return lenghSubstring;
}

/*---------------------------------------------
            FUNCTION my_STRTOK
    Breaks string str into a series
    of tokens separated by delim.
 --------------------------------------------*/
char *my_strtok(char *str, const char *delim) {
    static char *lastString = my_NULL;
    if (str == my_NULL) {
        str = lastString;
    }
    str += my_strspn(str, delim);
    if (*str == '\0') {
        lastString = str;
        return my_NULL;
    }
    char *token;
    token = str;
    str = my_strpbrk(token, delim);
    if (str == my_NULL) {
        lastString = my_memchr(token, '\0', my_strlen(token)+1);
    } else {
        *str = '\0';
        lastString = str + 1;
    }
    return token;
}

/*---------------------------------------------
            FUNCTION my_STRSPRINTF
 --------------------------------------------*/
typedef struct  {
    char flag[3];  // 0 = ' ', 1 = +, 2 = -
    int weight;
    int precision;
    char lenght;
} specifiredProrotype;

typedef struct  {
    int intArg;  // FLAG: 0
    short int shortIntArg;  // FLAG: 1
    long int longIntArg;  // FLAG: 2
    unsigned int unsignedIntArg;  // FLAG: 3
    unsigned short int unsignedShortIntArg;  // FLAG: 4
    unsigned long int unsignedLongIntArg;  // FLAG: 5
    double doubleArg;  // FLAG: 6
    int flagArg;
} typeAndValueArg;

// Start parse
//  Is the symbol a flag
int isFlag(const char *format) {
    int trueOrFalseAboutFlag = 0;  // True: return 1; False: return 0
    switch (*format) {
        case '-':
        case '+':
        case ' ':
            trueOrFalseAboutFlag = 1;
            break;
        default:
            trueOrFalseAboutFlag = 0;
            break;
    }
    return trueOrFalseAboutFlag;
}

// Is the symbol a number
int isNumber(const char *format) {
    int trueOrFalseAboutNumber = 0;
    if (*format >= '0' && *format <= '9') {
        trueOrFalseAboutNumber = 1;
    }
    return trueOrFalseAboutNumber;
}

// Is the symbol a lenght
int isLenght(const char *format) {
    int trueOrFalseAboutLenght = 0;
    switch (*format) {
        case 'h':
        case 'l':
            trueOrFalseAboutLenght = 1;
            break;
        default:
            trueOrFalseAboutLenght = 0;
            break;
    }
    return trueOrFalseAboutLenght;
}

// Is the symbol a type
int isType(const char *format) {
    int trueOrFalseAboutType = 0;
    switch (*format) {
        case 'd':
        case 'i':
        case 'f':
        case 'c':
        case 's':
        case 'u':
        case '%':
            trueOrFalseAboutType = 1;
            break;
        default:
            trueOrFalseAboutType = 0;
            break;
    }
    return trueOrFalseAboutType;
}

// Parsing weight or precision
char *parseWeightOrPrecision(const char *format, specifiredProrotype *prototype) {
    int chekToPoint = 0;
    if (*format == '.') {
        chekToPoint = 1;
        format++;
    }
    int arg = 0;
    while (isNumber(format) != 0) {
        arg = (arg + (*format - '0')) * 10;
        format++;
    }
    arg = arg/10;
    if (chekToPoint == 0) {
        prototype->weight = arg;
    } else if (chekToPoint == 1) {
        prototype->precision = arg;
    }
    return (char*)format;
}

// Parsing format a prototype
char *parseSpecifired(const char *format, specifiredProrotype *prototype) {
    format++;
    while (isType(format) != 1) {
        if (isFlag(format)) {
            if (*format == ' ') {
                prototype->flag[0] = *format;
            } else if (*format == '+') {
                prototype->flag[1] = *format;
            } else if (*format == '-') {
                prototype->flag[2] = *format;
            }
            format++;
        } else if (isNumber(format)) {
            format = parseWeightOrPrecision(format, prototype);
        } else if (*format == '.') {
            format = parseWeightOrPrecision(format, prototype);
        } else if (isLenght(format)) {
            prototype->lenght = *format;
            format++;
        }
    }
    return (char*)format;
}
// End parse

// get value argument
long long getArg(typeAndValueArg *valueArg) {
    long long number = 0;
    if (valueArg->flagArg == INT_FLAG) {
        number = valueArg->intArg;
    } else if (valueArg->flagArg == SHORT_INT_FLAG) {
        number = valueArg->shortIntArg;
    } else if (valueArg->flagArg == LONG_INT_FLAG) {
        number = valueArg->longIntArg;
    } else if (valueArg->flagArg == DOUBLE_FLAG) {
        number = valueArg->doubleArg;
    } else if (valueArg->flagArg == UNSIGNED_INT_FLAG) {
        number = valueArg->unsignedIntArg;
    } else if (valueArg->flagArg == UNSIGNED_SHORT_INT_FLAG) {
        number = valueArg->unsignedShortIntArg;
    } else if (valueArg->flagArg == UNSIGNED_LONG_INT_FLAG) {
        number = valueArg->unsignedLongIntArg;
    }
    return number;
}

// Write int to char array
char *intTochar(typeAndValueArg *valueArg, char *str) {
    long long int number = 0;
    long long int copyOfNumber = 0;
    number = llabs(getArg(valueArg));
    copyOfNumber = number;
    if (number != 0) {
        int length = 0;
        while (number != 0) {
            number = number / 10;
            length++;
        }
        for (int i = length; i > 0; i--) {
            number = copyOfNumber;
            for (int j = 0; j < i-1; j++) {
                number = number / 10;
            }
            number = number % 10;
            *str = number + '0';
            str++;
        }
    } else {
        *str = '0';
        str++;
    }
    *str = '\0';
    return str;
}

char *writeString(char *str, char *string) {
    while (*string !='\0') {
        *str = *string;
        str++;
        string++;
    }
    return str;
}

char *rightfloat(double right, char *str, int precision) {
    while (right > 0 && precision) {
        int bitRight = 0;
        right = right * 10;
        if (precision == 1) {
            bitRight = right + 0.5;
        } else {
            bitRight = right;
        }
        if (bitRight > 9 && precision == 1) {
            *str = '0';
            int count = 1;
            str--;
            while (*str == (9 + '0')) {
                *str = '0';
                count++;
                str--;
            }
            if (*str == '.') {
                count++;
                str--;
            }
            *str += 1;
            str += count + 1;
            precision--;
        } else {
            *str = bitRight + '0';
            precision--;
            right -= bitRight;
        }
        str++;
        if (right == 0 && precision) {
            while (precision) {
                *str = '0';
                str++;
                precision--;
            }
        }
    }
    return str;
}

char *floatTochar(char *str, int precision, typeAndValueArg *valueArg) {
    double arg = fabs(valueArg->doubleArg);
    if (precision == -1) {
        precision = 6;
    }
    if (precision > 0) {
        valueArg->intArg = arg;
    } else {
        valueArg->intArg = arg + 0.5;
    }
    double right = arg - valueArg->intArg;
    valueArg->flagArg = INT_FLAG;
    str = intTochar(valueArg, str);
    if (precision > 0) {
        *str = '.';
        str++;
        if (right == 0) {
            while (precision) {
                *str = '0';
                str++;
                precision--;
            }
        }
        str = rightfloat(right, str, precision);
    }
    return str;
}


// Применение флагов
char *writeFlag(char *str, specifiredProrotype *SpecifiredPrototype, typeAndValueArg *valueArg) {
    long long number = 0;
    number = getArg(valueArg);
    for (int flagIndex = 0; flagIndex < 3; flagIndex++) {
        if (SpecifiredPrototype->flag[flagIndex] == ' ') {
            *str = ' ';
            str++;
        } else if (SpecifiredPrototype->flag[flagIndex] == '+') {
            if (number >= 0) {
                *str = '+';
                str++;
            } else {
                *str = '-';
                str++;
            }
        }
    }
    if (number < 0 && (SpecifiredPrototype->flag[1] == '0')) {
        *str = '-';
        str++;
    }
    if ( (valueArg->flagArg >= INT_FLAG) && (valueArg->flagArg <= UNSIGNED_LONG_INT_FLAG) ) {
        str = intTochar(valueArg, str);
    } else if (valueArg->flagArg  == DOUBLE_FLAG) {
        str = floatTochar(str, SpecifiredPrototype->precision, valueArg);
    }
    return str;
}

char *writeWeight(char *str, int lenghtString, specifiredProrotype *prototype,  char *string) {
    int weightNumberChar = prototype->weight - lenghtString;
    if (prototype->flag[2] == '-') {
        if (weightNumberChar > 0) {
            str = writeString(str, string);
            for (int space = 0; space < weightNumberChar; space++) {
                *str = ' ';
                str++;
            }
        } else {
            str = writeString(str, string);
        }
    } else if (prototype->flag[2] == '0') {
        if (weightNumberChar > 0) {
            for (int space = 0; space < weightNumberChar; space++) {
                *str = ' ';
                str++;
            }
            str = writeString(str, string);
        } else {
            str = writeString(str, string);
        }
    }
    return str;
}

void writePrecision(char *str, int lenghtString, int precision, int type) {
    if ( (type >= INT_FLAG) && (type <= UNSIGNED_LONG_INT_FLAG) ) {
        if (precision  > lenghtString) {
            int lenght = precision - lenghtString;
            if (*str == '-' || *str == '+') {
                str++;
            }
            my_memmove(str+lenght, str, sizeof(char*));
            for (int symbol = 0; symbol < lenght; symbol++) {
                *str = '0';
                str++;
            }
        }
    } else {
        if (precision < lenghtString && precision != 0) {
            for (int symbol = 0; symbol < precision; symbol++) {
                str++;
            }
            *str = '\0';
        } else if (precision == 0 && type == 's') {
            *str = '\0';
        }
    }
}

char *integerType(specifiredProrotype *prototype, typeAndValueArg *valueArg, char *str, va_list args_) {
    if (prototype->lenght == 'l') {
        valueArg->longIntArg = va_arg(args_, long int);
        valueArg->flagArg = LONG_INT_FLAG;
    } else if (prototype->lenght == 'h') {
        valueArg->shortIntArg = (short int)va_arg(args_, int);
        valueArg->flagArg = SHORT_INT_FLAG;
    } else {
        valueArg->intArg = (int)va_arg(args_, int);
        valueArg->flagArg = INT_FLAG;
    }
    char numberChar[10000] = "";
    writeFlag(numberChar, prototype, valueArg);
    int stringLenght = my_strlen(numberChar);
    writePrecision(numberChar, stringLenght, prototype->precision, valueArg->flagArg);
    str = writeWeight(str, stringLenght, prototype, numberChar);
    return str;
}

char *floatType(specifiredProrotype *prototype, typeAndValueArg *valueArg, char *str, va_list args_) {
    valueArg->doubleArg = va_arg(args_, double);
    valueArg->flagArg = DOUBLE_FLAG;
    char numberChar[10000] = "";
    writeFlag(numberChar, prototype, valueArg);
    int stringLenght = my_strlen(numberChar);
    str = writeWeight(str, stringLenght, prototype, numberChar);
    return str;
}

char *unsignedType(specifiredProrotype *prototype, typeAndValueArg *valueArg, char *str, va_list args_) {
    char numberChar[10000] = "";
    if (prototype->lenght == 'l') {
        valueArg->unsignedLongIntArg = va_arg(args_, unsigned long int);
        valueArg->flagArg = UNSIGNED_LONG_INT_FLAG;
    } else if (prototype->lenght == 'h') {
        valueArg->unsignedShortIntArg = (unsigned short int)va_arg(args_, unsigned int);
        valueArg->flagArg = UNSIGNED_SHORT_INT_FLAG;
    } else {
        valueArg->unsignedIntArg = va_arg(args_, unsigned int);
        valueArg->flagArg = UNSIGNED_INT_FLAG;
    }
    writeFlag(numberChar, prototype, valueArg);
    int stringLenght = my_strlen(numberChar);
    writePrecision(numberChar, stringLenght, prototype->precision, valueArg->flagArg);
    str = writeWeight(str, stringLenght, prototype, numberChar);
    return str;
}

char *stringType(specifiredProrotype *prototype, char *str, va_list args_) {
    char *string = my_NULL;
    string = va_arg(args_, char*);
    char stringCopy[10000] = "";
    int symbol = 0;
    for (symbol = 0; *string != '\0'; symbol++) {
        stringCopy[ symbol ] = *string;
        string++;
    }
    stringCopy[ symbol ] = '\0';
    int stringLenght = my_strlen(stringCopy);
    if (prototype->precision == -1) {
        prototype->precision = stringLenght;
    }
    writePrecision(stringCopy, stringLenght, prototype->precision, STRING_FLAG);
    str = writeWeight(str, stringLenght, prototype, stringCopy);
    return str;
}

char *charType(specifiredProrotype *prototype, char *str, va_list args_) {
    char symbol = (char)va_arg(args_, int);
    char chStr[2] = "";
    chStr[0] = symbol;
    chStr[1] = '\0';
    str = writeWeight(str, 1, prototype, chStr);
    return str;
}

int my_sprintf(char *str, const char *format, ...) {
    char *str2 = str;
    va_list args;
    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%') {
            specifiredProrotype prototype = { {'0', '0', '0'}, 0, -1, '0'};
            typeAndValueArg valueArg = {0, 0, 0, 0, 0, 0, 0, 0};
            format = parseSpecifired(format, &prototype);
            if (*format == '%') {
                *str = '%';
                str++;
                format++;
            } else if (*format == 'd' || *format == 'i') {
                str = integerType(&prototype, &valueArg, str, args);
                format++;
            } else if (*format == 'c') {
                str = charType(&prototype, str, args);
                format++;
            } else if (*format == 's') {
                str = stringType(&prototype, str, args);

                format++;
            } else if (*format == 'f') {
                str = floatType(&prototype, &valueArg, str, args);
                format++;
            } else if (*format == 'u') {
                str = unsignedType(&prototype, &valueArg, str, args);
                format++;
            }
        } else {
            *str = *format;
            str++;
            format++;
        }
    }
    *str = '\0';
    va_end(args);
    return (int)my_strlen(str2);
}

/*------------------------------------------------
            FUNCTION my_STRERROR
    Searches an internal array for the error
    number errnum and returns a pointer to an
    error message string. You need to declare
    macros containing arrays of error messages
    for mac and linux operating systems. Error
    descriptions are available in the original
    library. Checking the current OS is carried
    out using directives.
 -----------------------------------------------*/
char *my_strerror(int errnum) {
    static char errorMessagesReturn[1024] = "";
    if (errnum < MAXERROR && errnum >= 0) {
        my_sprintf(errorMessagesReturn, "%s\0", errorMessage[errnum]);
    } else {
        my_sprintf(errorMessagesReturn, "%s %d\0", errorMessage[MAXERROR], errnum);
    }
    return errorMessagesReturn;
}

/*------------------------------------------------
                BONUS PART 5
 -----------------------------------------------*/

/*------------------------------------------------
            FUNCTION my_TO_UPPER
    Returns a copy of string (str) converted
    to uppercase. In case of any error,
    return my_NULL.
 -----------------------------------------------*/
void *my_to_upper(const char *str) {
    char *copyUpperString = my_NULL;
    if (str != my_NULL) {
        copyUpperString = (char*) calloc(my_strlen(str) + 1, sizeof(char));
        if (copyUpperString == my_NULL) {
            exit(0);
        }
        int symbol = 0;
        for (symbol = 0; str[symbol] != 0; symbol++) {
            if ((str[symbol] >= 97) && (str[symbol] <= 122))  {
                copyUpperString[symbol] = str[symbol] - 32;
            } else {
                copyUpperString[symbol] = str[symbol];
            }
        }
        copyUpperString[symbol] = '\0';
    }

    return copyUpperString;
}

/*------------------------------------------------
            FUNCTION my_TO_LOWER
   Returns a copy of string (str) converted
   to lowercase. In case of any error,
   return my_NULL.
 -----------------------------------------------*/
void *my_to_lower(const char *str) {
    char *copyLowerString = my_NULL;
    if (str != my_NULL) {
        copyLowerString = (char*) calloc(my_strlen(str) + 1, sizeof(char));
        if (copyLowerString == my_NULL) {
            exit(0);
        }
        int symbol = 0;
        for (symbol = 0; str[symbol] != 0; symbol++) {
            if ((str[symbol] > 64) && (str[symbol] < 91))  {
                copyLowerString[symbol] = str[symbol] + 32;
            } else {
                copyLowerString[symbol] = str[symbol];
            }
        }
        copyLowerString[symbol] = '\0';
    }
    return copyLowerString;
}

/*------------------------------------------------
            FUNCTION my_INSERT
    Returns a new string in which a
    specified string (str) is inserted
    at a specified index position (start_index)
    in the given string (src). In case of
    any error, return my_NULL.
 -----------------------------------------------*/
void *my_insert(const char *src, const char *str, my_size_t start_index) {
    char *newInsertStr = my_NULL;
    if (str != my_NULL && src != my_NULL) {
        newInsertStr = (char*) calloc(my_strlen(str) + my_strlen(src) + 1, sizeof(char));
        if (newInsertStr == my_NULL) {
            exit(0);
        }
        int symbol = 0;
        while (*src != '\0') {
            if (symbol == start_index) {
                while (*str != '\0') {
                    newInsertStr[symbol] = *str;
                    str++;
                    symbol++;
                }
            } else {
                newInsertStr[symbol] = *src;
                src++;
                symbol++;
            }
        }
        newInsertStr[symbol] = '\0';
    }
    return newInsertStr;
}

/*------------------------------------------------
            FUNCTION my_TRIM
    Returns a new string in which all
    leading and trailing occurrences of
    a set of specified characters
    (trim_chars) from the given string
    (src) are removed. In case of any error,
    return my_NULL/
 -----------------------------------------------*/
int checkTrim(const char *src, const char *trim_chars) {
    int doneTrim = 0;
    while (*trim_chars != '\0') {
        if (*src == *trim_chars) {
            doneTrim = 0;
            break;
        } else {
            doneTrim = 1;
            trim_chars++;
        }
    }
    return doneTrim;
}

void *my_trim(const char *src, const char *trim_chars) {
    char *newTrimStr = my_NULL;
    if (src != my_NULL && trim_chars != my_NULL) {
        newTrimStr = (char *) calloc(my_strlen(src) + 1, sizeof(char));
        if (newTrimStr == my_NULL) {
            exit(0);
        }
        int doneTrim = 0;
        while (*src != '\0') {
            doneTrim = checkTrim(src, trim_chars);
            if (doneTrim == 1) {
                break;
            }
            src++;
        }
        const char *startString = src;
        while (*src != '\0') {
            src++;
        }
        doneTrim = 0;
        while (doneTrim == 0) {
            src--;
            doneTrim = checkTrim(src, trim_chars);
            if (doneTrim == 1) {
                break;
            }
        }
        const char *endString = src;
        endString++;
        int symbol = 0;
        for (symbol = 0; startString != endString; symbol++) {
            newTrimStr[symbol] = *startString;
            startString++;
        }
        newTrimStr[symbol] = '\0';
    }
    return newTrimStr;
}
