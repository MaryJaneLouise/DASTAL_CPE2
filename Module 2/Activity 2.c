#include <stdio.h>

void ModuleTwoActivityTwo() {
    int i, j;
    int rowPascal, resultPascal = 1;

    printf("Enter the number of rows to be printed in the Pascal's Triangle: ");
    scanf("%d", &rowPascal);

    printf("\nResult:\n");
    for (i = 0; i < rowPascal; i++) {
        for (j = 0; j <= i; j++) {
            if (i == 0 || j == 0) {
                resultPascal = 1;
            }
            else {
                resultPascal = resultPascal * (i - j + 1) / j;
            }

            printf("%d", resultPascal);
            if (i - j == 0) {
                printf("");
            }
            else {
                printf("\t");
            }
        }
        printf("\n");
    }
}

int main() {
    ModuleTwoActivityTwo();
    return 0;
}