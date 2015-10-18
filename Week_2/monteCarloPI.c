

#include <stdio.h>
#include <stdlib.h>

#define R 1.0

/* Return a random double between 0 and 1 */
double randDouble();

int hit(double x, double y);

int main(void)
{
	double x, y, h_c = 0, h_a = 0;
	double PI;

	while (1){
		h_a++;

		x = randDouble();
		y = randDouble();

		if (hit(x, y)){
			h_c++;
		}

		PI = 4.0 * h_c / h_a;
		printf("%f\n", PI);
	}
}

double randDouble()
{
	return (double)rand() / (double)RAND_MAX;
}

int hit(double x, double y)
{
	if (x * x + y * y <= R * R){
		return 1;
	}

	return 0;
}