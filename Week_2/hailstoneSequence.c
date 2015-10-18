

#include <stdio.h>

#define CAP 50000

int getNext(int n);

int getSequenseLength(int n);

int getSequenceMax(int n);

int main(void)
{
	int i;
	int longestStartNum = 1, largestStartNum = 1,
		len = 1, maxVal = 1,
		curLen, curVal;
		

	for (i = 1; i < CAP; i++){
		curLen = getSequenseLength(i);
		curVal = getSequenceMax(i);

		if (curLen > len){
			len = curLen;
			longestStartNum = i;
		}

		if (curVal > maxVal){
			maxVal = curVal;
			largestStartNum = i;
		}
	}

	printf("Longest sequence - Starting number: %d, Length: %d\n", longestStartNum, len);
	printf("Largest number - Starting number: %d, Largest number: %d\n", largestStartNum, maxVal);

	return 0;
}

int getNext(int n)
{
	if (n % 2 == 0){
		return n / 2;
	}
	else{
		return 3 * n + 1;
	}
}

int getSequenseLength(int n)
{
	int len = 1;

	while (n != 1){
		n = getNext(n);
		len++;
	}

	return len;
}

int getSequenceMax(int n)
{
	int max = 1;

	while (n != 1){
		max = n > max ? n : max;
		n = getNext(n);
	}

	return max;
}