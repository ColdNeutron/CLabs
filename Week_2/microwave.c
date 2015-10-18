

#include <stdio.h>
#include <stdlib.h>

#define DIVUP(a, b) a % b == 0 ? a / b : a / b + 1

#define NUM_BUTTONS 3
#define BUTTON_1 600
#define BUTTON_2 60
#define BUTTON_3 10

int getButtonPresses(int cookingTime);

int main(void)
{
    int cookingTime = 0;
    int presses = 0;

    do{
        printf("Type the time required\n");
        if(scanf("%d", &cookingTime) != 1){
            return 1;
        }

        if(cookingTime != -1){
            presses = getButtonPresses(cookingTime);
            printf("Number of button presses = %d\n", presses);
        }
    } while(cookingTime != -1);

    return 0;
}

int getButtonPresses(int cookingTime)
{
    int i, presses = 0;
    static int buttons[] = {BUTTON_1, BUTTON_2, BUTTON_3};

    for(i = 0; i < NUM_BUTTONS; i++){
        if(i == NUM_BUTTONS - 1){
            presses += DIVUP(cookingTime, buttons[i]);
        }
        else{
            presses += cookingTime / buttons[i];
        }

        cookingTime %= buttons[i];
    }

    return presses;
}
