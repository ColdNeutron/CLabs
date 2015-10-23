

#include <stdio.h>
#include <stdlib.h>

#define SZ_Y 2
#define SZ_X 5

void func1(int arr[][SZ_X]);

void func2(int *arr);

int main(void) {
    int arr_bracket[SZ_Y][SZ_X];
    int i, j;

    printf("\nfunc1(int arr[][SZ_X])\n\n");    

    printf("Before:\n");
    for (i = 0; i < SZ_Y; i++) {
        for (j = 0; j < SZ_X; j++) {
            arr_bracket[i][j] = (i + 1) * (j + 1);
        }
    }

    for (i = 0; i < SZ_Y; i++) {
        for (j = 0; j < SZ_X; j++) {
            printf("%3d", arr_bracket[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    func1(arr_bracket);

    printf("After:\n");
    for (i = 0; i < SZ_Y; i++) {
        for (j = 0; j < SZ_X; j++) {
            printf("%3d", arr_bracket[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    printf("\nfunc2(int *arr)\n\n");

    printf("Before:\n");
    for (i = 0; i < SZ_Y; i++) {
        for (j = 0; j < SZ_X; j++) {
            arr_bracket[i][j] = (i + 1) * (j + 1);
        }
    }

    for (i = 0; i < SZ_Y; i++) {
        for (j = 0; j < SZ_X; j++) {
            printf("%3d", arr_bracket[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    func2((int *)arr_bracket);

    printf("After:\n");
    for (i = 0; i < SZ_Y; i++) {
        for (j = 0; j < SZ_X; j++) {
            printf("%3d", arr_bracket[i][j]);
        }

        printf("\n");
    }
    printf("\n");


    return 0;
}

void func1(int arr[][SZ_X]) {
    int i, j;

    for (i = 0; i < SZ_Y; i++) {
        for (j = 0; j < SZ_X; j++) {
            arr[i][j] = 0;
        }
    }
}

void func2(int *arr) {
    int i, j;

    for (i = 0; i < SZ_Y; i++) {
        for (j = 0; j < SZ_X; j++) {
            *(arr + i * SZ_X + j) = 0;
        }
    }
}


