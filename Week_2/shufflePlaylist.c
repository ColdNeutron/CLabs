

#include <stdio.h>
#include <stdlib.h>

void randomSwap(int *arr, int len);

void shuffle(int *playlist, int len);

void printPlaylist(int * playlist, int len);

int main(void)
{
	int songs = 0, i;
	int *playlist = NULL;
	
	printf("How many songs required ? ");
	scanf("%d", &songs);
	
	if((playlist = (int *)malloc(sizeof(int) * songs)) == NULL){
		return 1;
	}
	
	for(i = 0; i < songs; i++){
		playlist[i] = i + 1;
	}
	
	shuffle(playlist, songs);
	
	printPlaylist(playlist, songs);
	
	free(playlist);
	
	return 0;
}

void randomSwap(int *arr, int len)
{
	int idx0, idx1, temp;
	idx0 = rand() % len;
	idx1 = rand() % len;
	
	temp = arr[idx0];
	arr[idx0] = arr[idx1];
	arr[idx1] = temp;
}

void shuffle(int *playlist, int len)
{
	int i;
	
	for(i = 0; i < len; i++){
		randomSwap(playlist, len);
	}
}

void printPlaylist(int *playlist, int len)
{
	int i;
	
	for(i = 0; i < len; i++){
		printf("%d ", playlist[i]);
	}
	printf("\n");
}

