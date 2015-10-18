

#include <stdio.h>
#include <ctype.h>

#define UPPER_SUM 'A' + 'Z'
#define LOWER_SUM 'a' + 'z'


int scode(int a);


int main(void)
{
	char c;

	while ((c = getchar()) != EOF){
		c = scode(c);
		putchar(c);
	}

	return 0;
}


int scode(int a)
{
	if (isupper(a)){
		return UPPER_SUM - a;
	}

	if (islower(a)){
		return LOWER_SUM - a;
	}

	return a;
}