

/*
- Converts roman numerals in range 1 - 3999 to arabic number
- Both lower and upper case are acceptable
- Invalid squences are rejected
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



#define MAX_ALLOWED_REPEAT 3
#define SYMBOL_SIZE 3
#define NUM_SYMBOLS 13


int romanToArabic(char *roman);

void exitOnInvalidSequence(char *roman, char *symbolArray);

void initSymbolArray(char *symbolArray);

void stringToUpper(char *str);

int isValidSequence(char *roman, char *symbolArray);

int isValidSymbol(char *symbolArray, char *symbol);

int checkSymbolValidity(char *roman, char *symbolArray);

int checkSymbolRepetition(char *roman);

int checkSymbolOrder(char *roman, char *symbolArray);

int indexOf(char *symbolArray, char *symbol);

int getNextSymbol(char *roman, char *symbol);

int needTwoSymbols(char *roman);

int lookup(char *symbolArray, char *symbol);


int main(int argc, char **argv) {
    if (argc == 2) {
        printf("The roman numeral %s is equal to %d\n", argv[1], romanToArabic (argv[1]));
    } else {
        printf("ERROR: Incorrect usage, try e.g. %s XXI\n", argv[0]);
    }

    return 0;
}


int romanToArabic(char *roman) {
    char *symbolArray;
    char symbol[SYMBOL_SIZE];
    int value, sum = 0;

    symbolArray = (char *)malloc(NUM_SYMBOLS * SYMBOL_SIZE * sizeof(char));
    if (symbolArray == NULL) {
        printf("ERROR: memery allocation failure\n");
        exit(1);
    }

    initSymbolArray(symbolArray);
    stringToUpper(roman);
    exitOnInvalidSequence(roman, symbolArray);

    while (*roman != '\0') {
        roman += getNextSymbol(roman, symbol);
        value = lookup(symbolArray, symbol);
        sum += value;
    }

    free(symbolArray);

    return sum;
}

void exitOnInvalidSequence(char *roman, char *symbolArray) {
    if (!isValidSequence(roman, symbolArray)) {
        printf("ERROR: \"%s\" is not a valid sequence\n", roman);
        exit(2);
    }
}

void initSymbolArray(char *symbolArray) {
    char data[NUM_SYMBOLS][SYMBOL_SIZE] = {
        "I",
        "IV",
        "V",
        "IX",
        "X",
        "XL",
        "L",
        "XC",
        "C",
        "CD",
        "D",
        "CM",
        "M"
    };
    int i;

    for (i = 0; i < NUM_SYMBOLS; i++) {
        strcpy(symbolArray + i * SYMBOL_SIZE, &data[i][0]);
    }
}

void stringToUpper(char *str) {
    for (; *str != '\0'; str++) {
        *str = (char)toupper(*str);
    }
}

/* checks if input is a valid sequence of roman numerals */
int isValidSequence(char *roman, char *symbolArray) {
    if (checkSymbolValidity(roman, symbolArray) == 0 ||
        checkSymbolRepetition(roman) == 0 ||
        checkSymbolOrder(roman, symbolArray) == 0) {
        return 0;
    }

    return 1;
}

int isValidSymbol(char *symbolArray, char *symbol) {
    if (indexOf(symbolArray, symbol) == -1) {
        return 0;
    }

    return 1;
}

/* check is string contains any invalid symbols e.g. 'a', '2', '!', etc. */
int checkSymbolValidity(char *roman, char *symbolArray) {
    char symbol[SYMBOL_SIZE];

    while (*roman != '\0') {
        roman += getNextSymbol(roman, symbol);

        if (!isValidSymbol(symbolArray, symbol)) {
            return 0;
        }
    }

    return 1;
}

/* check if any symbol is repeated too many times e.g. 'IIII' */
int checkSymbolRepetition(char *roman) {
    char cur = '\0', prev = '\0';
    int flag = 1, cnt = 0;

    for (; *roman != '\0'; roman++) {
        if (flag) {
            cur = *roman;
            cnt = 1;
            flag = 0;
        } else {
            prev = cur;
            cur = *roman;
            cnt = (prev == cur ? cnt + 1 : 1);

            if (cnt > MAX_ALLOWED_REPEAT) {
                return 0;
            }
        }
    }

    return 1;
}

/* check if all symbols are in the correct order e.g. 'IM', 'IVI', etc are not valid */
int checkSymbolOrder(char *roman, char *symbolArray) {
    char cur[SYMBOL_SIZE], prev[SYMBOL_SIZE];
    int flag = 1;

    while (*roman != '\0') {
        if (flag) {
            roman += getNextSymbol(roman, cur);
            flag = 0;
        } else {
            strcpy(prev, cur);
            roman += getNextSymbol(roman, cur);

            if (indexOf(symbolArray, prev) < indexOf(symbolArray, cur)) {
                return 0;
            }

            if ((strlen(prev) == SYMBOL_SIZE - 1 || strlen(cur) == SYMBOL_SIZE - 1) &&
                ((int)(log10(lookup(symbolArray, cur))) == (int)(log10(lookup(symbolArray, prev))))) {
                return 0;
            }
        }
    }

    return 1;
}

int indexOf(char *symbolArray, char *symbol) {
    int i;

    for (i = 0; i < NUM_SYMBOLS; i++) {
        if (strcmp(symbolArray + i * SYMBOL_SIZE, symbol) == 0) {
            return i;
        }
    }

    return -1;
}

int getNextSymbol(char *roman, char *symbol) {
    int len = 0;

    if (needTwoSymbols(roman)) {
        *symbol = *roman;
        *(symbol + 1) = *(roman + 1);
        len = 2;
    } else {
        *symbol = *roman;
        len = 1;
    }

    *(symbol + len) = '\0';

    return len;
}

int needTwoSymbols(char *roman) {
    if (*(roman + 1) == '\0') {
        return 0;
    }

    if (*roman == 'I' && (*(roman + 1) == 'V' || *(roman + 1) == 'X')) {
        return 1;
    }

    if (*roman == 'X' && (*(roman + 1) == 'L' || *(roman + 1) == 'C')) {
        return 1;
    }

    if (*roman == 'C' && (*(roman + 1) == 'D' || *(roman + 1) == 'M')) {
        return 1;
    }

    return 0;
}

int lookup(char *symbolArray, char *symbol) {
    int symbolValue[NUM_SYMBOLS] = {
        1,
        4,
        5,
        9,
        10,
        40,
        50,
        90,
        100,
        400,
        500,
        900,
        1000
    };

    return symbolValue[indexOf(symbolArray, symbol)];
}
