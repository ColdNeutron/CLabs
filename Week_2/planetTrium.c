

#include <stdio.h>


int isVowel(char c);

int isConsonant(char c);

char nextVowel(char c);

char nextConsonant(char c);

int main(void)
{
	int counter = 1;
	char firstLetter = 'b';
	char secondLetter = 'a';
	char thirdLetter = 'b';
	
	for(firstLetter = 'b'; firstLetter <= 'z'; firstLetter++){
		for(secondLetter = 'a'; secondLetter <= 'z'; secondLetter++){
			for(thirdLetter = 'b'; thirdLetter <= 'z'; thirdLetter++){
				if(isConsonant(firstLetter) && isVowel(secondLetter) && isConsonant(thirdLetter)){
					printf("%4d %c%c%c\n", counter++, firstLetter, secondLetter, thirdLetter);
				}
			}
		}
	}

	return 0;
}

int isVowel(char c)
{
	switch (c){
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return 1;
	default:
		return 0;
	}
}

int isConsonant(char c)
{
	return !isVowel(c);
}

char nextVowel(char c)
{
	switch (c){
	case 'a':
		return 'e';
	case 'e':
		return 'i';
	case 'i':
		return 'o';
	case 'u':
	default:
		return -1;
	}
}

char nextConsonant(char c)
{
	if (c == 'z'){
		return -1;
	}

	do{
		c++;
	} while (isVowel(c));

	return c;
}