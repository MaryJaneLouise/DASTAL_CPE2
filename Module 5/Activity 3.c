#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void factorialNumber() {
    int inputNumber;
    double i, factorialResult = 1;
    printf("Enter the number you want to be solved using factorial: ");
    scanf("%d", &inputNumber);

    if (inputNumber < 0) {
        printf("\nTry another number.");
    }
    else {
        if (inputNumber >= 0 && inputNumber <= 170) {
            for (i = 1; i <= inputNumber; i++) {
                factorialResult = factorialResult * i;
            }
            printf("Result = %0.0lf\n", factorialResult);
        }
        else if (inputNumber > 170) {
            printf("Unfortunately, the program will likely to print 'inf', which means it has reached its limit.\n");
            for (i = 1; i <= inputNumber; i++) {
                factorialResult = factorialResult * i;
            }
            printf("Result = %0.0lf\n", factorialResult);
        }
    }
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
