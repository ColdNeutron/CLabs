

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define CODE_LEN 4
#define LABIAL "BFPV"
#define GUTT_SIB "CGJKQSXZ"
#define DENTAL "DT"
#define LONG_LIQ "L"
#define NASAL "MN"
#define SHORT_LIQ "R"
#define SKIP "AEHIOUWY"


void generateCode(char *name, char *code);

int getNextDigit(char *name, char *code, int idx);

int lookup(char c);

int isIn(char c, char *str);


int main(int argc, char **argv)
{
	printf("%c %s %d\n", 'c', "chain", isIn('c', "chain"));
	printf("%c %s %d\n", 'c', "beckon", isIn('c', "beckon"));
	printf("%c %s %d\n", 'c', "apples", isIn('c', "apples"));

	/*
	char soundexCode[4];
	generateCode(argv[1], soundexCode);

	if(argc == 2){
        printf("The Soundex code for %s is %s\n", argv[1], soundexCode);
    }
    else{
        printf("ERROR: Incorrect usage, try e.g. %s Smith\n", argv[0]);
    }
    */

	return 0;
}


void generateCode(char *name, char *code)
{
	int i, moveCur;
	char *cur = name;

	*code = toupper(*cur++);

	for(i = 1; i < CODE_LEN; i++){
		moveCur = getNextDigit(cur, code, i);
		cur += moveCur;
	}
}

int getNextDigit(char *name, char *code, int idx)
{
	return 0;
}

int lookup(char c)
{
	c = toupper(c);

	if(isIn(c, LABIAL)){
		return 1;
	}

	if(isIn(c, GUTT_SIB)){
		return 2;
	}

	if(isIn(c, DENTAL)){
		return 3;
	}

	if(isIn(c, LONG_LIQ)){
		return 4;
	}

	if(isIn(c, NASAL)){
		return 5;
	}

	if(isIn(c, SHORT_LIQ)){
		return 6;
	}

	if(isIn(c, SKIP)){
		return 0;
	}

	return -1;
}

int isIn(char c, char *str)
{
	for(; *str != '\0'; str++){
		if(c == *str){
			return 1;
		}
	}

	return 0;
}