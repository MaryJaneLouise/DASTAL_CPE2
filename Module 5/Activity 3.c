#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float factorialFormula(int inputNumber) {

    if (inputNumber < 0) {
        printf("\nTry another number. You entered a negative number");
    }
    else {
        if (inputNumber >= 1) {
            return inputNumber * factorialFormula(inputNumber - 1);
        }
        else {
            return 1;
        }
    }


}
int factorialNumber() {
    int inputNumber;
    printf("Enter the number you want to be solved using factorial: ");
    scanf("%d", &inputNumber);

    printf("If the program printed 'inf', it means to say that it has reached its limit.\n");
    printf("Result = %0.0lf\n", factorialFormula(inputNumber));
}

int main() {
    int option;

    factorialNumber();

    for(;;) {
        printf("Do you want to continue?\n"
               "1 - Yes\n"
               "2 - No\n"
               "Answer: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\n\n");
                factorialNumber();
                break;

            case 2:
                printf("Good day!");
                return 0;

            default:
                printf("Since you didn't pick any of the choices, the program will shut down now.");
                return 0;
        }
    }
}
