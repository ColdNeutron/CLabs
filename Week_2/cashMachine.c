

#include <stdio.h>
#include <stdlib.h>

#define DENOMINATION 20


int getUpperBound(int a);

int getLowerBound(int a);


int main(void)
{
	int amount, lower, upper;

	do{
		printf("How much money would you like ? ");
		scanf("%d", &amount);

		if (amount % DENOMINATION == 0){
			printf("OK, dispensing ...\n");
		}
		else{
			upper = getUpperBound(amount);
			lower = getLowerBound(amount);

			printf("I can give you %d or %d, try again.\n", lower, upper);
		}
	} while (amount % DENOMINATION != 0);

	return 0;
}


int getUpperBound(int a)
{
	return (a / DENOMINATION + 1) * DENOMINATION;
}

int getLowerBound(int a)
{
	return (a / DENOMINATION) * DENOMINATION;
}