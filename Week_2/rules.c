

#include <stdio.h>
#include <stdlib.h>

#define LINE_LENGTH 30
#define N_ITER 40

void randomize(int *arr);

void singleOn(int *arr);

void printArray(int *arr);

void copyArray(int *a, int *b);

void getNextLine(int *currentLine, int *nextLine);

int main(void)
{
    int currentLine[LINE_LENGTH], nextLine[LINE_LENGTH];
    int selection, i;

    printf("Randomized line: 1, Single 'ON': 2 ? ");
    if(scanf("%d", &selection) != 1){
        return 1;
    }

    switch(selection){
        case 1:
            randomize(currentLine);
            break;
        case 2:
            singleOn(currentLine);
            break;
        default:
            return 1;
    }

    printArray(currentLine);

    for(i = 0; i < N_ITER; i++){
        getNextLine(currentLine, nextLine);
        copyArray(currentLine, nextLine);
        printArray(currentLine);
    }

    return 0;
}

void randomize(int *arr)
{
    int i;

    for(i = 0; i < LINE_LENGTH; i++){
        arr[i] = rand() % 2;
    }
}

void singleOn(int *arr)
{
    int i;

    for(i = 0; i < LINE_LENGTH; i++){
        arr[i] = 0;
    }

    arr[LINE_LENGTH - 4] = 1;
}

void printArray(int *arr)
{
    int i;

    for(i = 0; i < LINE_LENGTH; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void copyArray(int *a, int *b)
{
    int i;

    for(i = 0; i < LINE_LENGTH; i++){
        a[i] = b[i];
    }
}

void getNextLine(int *currentLine, int *nextLine)
{
    int i, code;

    nextLine[0] = 0;
    nextLine[LINE_LENGTH - 1] = 0;

    for(i = 1; i < LINE_LENGTH - 1; i++){
        code = 100 * currentLine[i - 1] + 10 * currentLine[i] + currentLine[i + 1];

        switch(code){
            case 111:
                nextLine[i] = 0;
                break;
            case 110:
                nextLine[i] = 1;
                break;
            case 101:
                nextLine[i] = 1;
                break;
            case 100:
                nextLine[i] = 0;
                break;
            case 11:
                nextLine[i] = 1;
                break;
            case 10:
                nextLine[i] = 1;
                break;
            case 1:
                nextLine[i] = 1;
                break;
            case 0:
                nextLine[i] = 0;
                break;
        }
    }
}
