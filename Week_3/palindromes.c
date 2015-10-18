

/*
 * Gets a line from the user and checks if it is a palindrome
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX_SIZE 2048


void getLine(char *str);

int getLen(char *str);

void copyStr(char *src, char *dst);

void cleanStr(char *src); /* Removes all non-alphabet characters and convert remaining letters to lower case */

void reverseStr(char *src);

int isEqual(char *str1, char *str2);

int isPalindrome(char *str);


int main(void)
{
	char str[MAX_SIZE];

	printf("Enter a string : ");
	getLine(str);

	if(isPalindrome(str)){
		printf("That IS a palindrome\n");
	}
	else{
		printf("That IS NOT a palindrome\n");
	}

	return 0;
}


void getLine(char *str)
{
	char in;

	while((in = getchar()) != '\n'){
		*str++ = in;
	}

	*str = '\0';
}

int getLen(char *str)
{
	int len = 0;

	while(*str++ != '\0'){
		len++;
	}

	return len;
}

void copyStr(char *src, char *dst)
{
	while(*src != '\0'){
		*dst++ = *src++;
	}

	*dst = '\0';
}

void cleanStr(char *src)
{
	char temp[MAX_SIZE];
	int len, newLen = 0, i;

	len = getLen(src);

	for(i = 0; i < len; i++){
		if(isalpha(src[i])){
			temp[newLen++] = tolower(src[i]);
		}
	}

	temp[newLen] = '\0';

	copyStr(temp, src);
}

void reverseStr(char *src)
{
	char temp[MAX_SIZE];
	int i, len;

	len = getLen(src);

	for(i = 0; i < len; i++){
		temp[len - 1 - i] = src[i];
	}

	temp[i] = '\0';

	copyStr(temp, src);
}

int isEqual(char *str1, char *str2)
{
    while(*str1 != '\0'){
        if(*str2 == '\0'){
            return 0;
        }

        if(*str1 != *str2){
            return 0;
        }

        str1++;
        str2++;
    }

    if(*str2 != '\0'){
        return 0;
    }

    return 1;
}

int isPalindrome(char *str)
{
	char temp[MAX_SIZE];

	cleanStr(str);
	copyStr(str, temp);
	reverseStr(temp);

	if(isEqual(str, temp)){
		return 1;
	}

	return 0;
}