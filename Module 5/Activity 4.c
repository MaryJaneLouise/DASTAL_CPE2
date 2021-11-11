#include <stdio.h>

int fibonacciSeriesFormula(int inputNumber) {
    if (inputNumber == 0 || inputNumber == 1) {
        return inputNumber;
    }
    else {
        return (fibonacciSeriesFormula(inputNumber - 1) + fibonacciSeriesFormula(inputNumber - 2));
    }
}

void fibonacciSeries() {
    int inputNumber;
    int i, fibonacciLoop = 0;

    printf("Enter the number to print for Fibonacci Series: ");
    scanf("%d", &inputNumber);

    if (inputNumber >= 0) {
        if (inputNumber == 0) {
            printf("Result = 0");
        }
        else {
            printf("Result = ");
            for (i = 1; i <= inputNumber; i++) {
                printf("%d ", fibonacciSeriesFormula(fibonacciLoop));
                fibonacciLoop++;
            }
        }
    }
    else {
        printf("Try again. You entered a negative number.\n");
    }

}
int main() {
    int option;

    fibonacciSeries();

    for(;;) {
        printf("\n\nDo you want to continue?\n"
               "1 - Yes\n"
               "2 - No\n"
               "Answer: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\n\n");
                fibonacciSeries();
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