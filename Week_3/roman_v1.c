

/* lookups roman numerals in range 1 - 3999 to arabic number */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define SUBSTR_SIZE 3
#define NUM_SYMBOLS 13


int romanToArabic(char *roman);

int getNextSubstr(char *roman, char *substr);

int needTwoCharacters(char *roman);

int lookup(char *substr);


int main(int argc, char **argv)
{
    if(argc == 2){
        printf("The roman numeral %s is equal to %d\n", argv[1], romanToArabic(argv[1]));
    }
    else{
        printf("ERROR: Incorrect usage, try e.g. %s XXI\n", argv[0]);
    }

    return 0;
}


int romanToArabic(char *roman)
{
    char substr[SUBSTR_SIZE];

    if (*roman == '\0') {
        return 0;
    }

    roman += getNextSubstr(roman, substr);
    return lookup(substr) + romanToArabic(roman);
}

int getNextSubstr(char *roman, char *substr)
{
    int len = 0;

    if(needTwoCharacters(roman)){
        *substr = *roman;
        *(substr + 1) = *(roman + 1);
        len = 2;
    }
    else{
        *substr = *roman;
        len = 1;
    }

    *(substr + len) = '\0';

    return len;
}

int needTwoCharacters(char *roman)
{
    if(*(roman + 1) == '\0'){
        return 0;
    }

    if(*roman == 'I' && (*(roman + 1) == 'V' || *(roman + 1) == 'X')){
        return 1;
    }

    if(*roman == 'X' && (*(roman + 1) == 'L' || *(roman + 1) == 'C')){
        return 1;
    }

    if(*roman == 'C' && (*(roman + 1) == 'D' || *(roman + 1) == 'M')){
        return 1;
    }

    return 0;
}

int lookup(char *substr)
{
    static char symbol[NUM_SYMBOLS][3] = {"I", "V", "X", "L", "C", "D", "M",
        "IV", "IX", "XL", "XC", "CD", "CM"};

    static int symbolValue[NUM_SYMBOLS] = {1, 5, 10, 50, 100, 500, 1000,
        4, 9, 40, 90, 400, 900};

    int i;

    for(i = 0; i < NUM_SYMBOLS; i++){
        if(strcmp(substr, symbol[i]) == 0){
            return symbolValue[i];
        }
    }

    return -1;
}


