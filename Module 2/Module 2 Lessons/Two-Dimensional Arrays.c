#include <stdio.h>

void TwoDimensionalArraysEx1() {
    //printing pre-defined numbers for 2D arrays
    int i, j;
    int arrayEx[2][2] = {12, 34, 56, 78};

    for (i = 0; i < 2; i++) {
        printf("\n");

        for (j = 0; j < 2; j++) {
            printf("%d\t", arrayEx[i][j]);
        }
    }
}

void TwoDimensionalArraysEx2() {
    //printing user-defined numbers for 2D arrays
    int i, j;
    int rowArray, columnArray, arrayEx[128][128];

    printf("Enter the number of rows of the array: ");
    scanf("%d", &rowArray);

    printf("Enter the number of columns of the array: ");
    scanf("%d", &columnArray);

    printf("\nEnter the elements for the array:\n");
    for (i = 0; i < rowArray; i++) {
        for (j = 0; j < columnArray; j++) {
            printf("Element [%d][%d] = ", i, j);
            scanf("%d", &arrayEx[i][j]);
        }
    }

    printf("\nResult:\n");
    for (i = 0; i < rowArray; i++) {
        for (j = 0; j < columnArray; j++) {
            printf("%d\t", arrayEx[i][j]);
            if (j == rowArray - 1) {
                printf("\n");
            }
        }
    }
}

void TwoDimensionalArraysEx3() {
    //printing the two matrices and adding them both
    int i, j;
    int rowMatrix, columnMatrix;
    int matrixOne[128][128], matrixTwo[128][128], matrixSumPerMatrix[128][128], matrixTotal;

    printf("Enter the number of rows for the two matrices: ");
    scanf("%d", &rowMatrix);

    printf("Enter the number of columns for the two matrices: ");
    scanf("%d", &columnMatrix);

    printf("\nEnter the elements for the First Matrix:\n");
    for (i = 0; i < rowMatrix; i++) {
        for (j = 0; j < columnMatrix; j++) {
            printf("First Matrix | Element [%d][%d] = ", i, j);
            scanf("%d", &matrixOne[i][j]);
        }
    }

    printf("\nEnter the elements for the Second Matrix:\n");
    for (i = 0; i < rowMatrix; i++) {
        for (j = 0; j < columnMatrix; j++) {
            printf("Second Matrix | Element [%d][%d] = ", i, j);
            scanf("%d", &matrixTwo[i][j]);
        }
    }

    printf("\nFirst Matrix:\n");
    for (i = 0; i < rowMatrix; i++) {
        for (j = 0; j < columnMatrix; j++) {
            printf("%d\t", matrixOne[i][j]);
            if (j == rowMatrix - 1) {
                printf("\n");
            }
        }
    }

    printf("\nSecond Matrix:\n");
    for (i = 0; i < rowMatrix; i++) {
        for (j = 0; j < columnMatrix; j++) {
            printf("%d\t", matrixTwo[i][j]);
            if (j == rowMatrix - 1) {
                printf("\n");
            }
        }
    }

    printf("\nSolution:\n");
    for (i = 0; i < rowMatrix; i++) {
        for (j = 0; j < columnMatrix; j++) {
            printf("(%d + %d)\t", matrixOne[i][j], matrixTwo[i][j]);
            if (j == rowMatrix - 1) {
                printf("\n");
            }
        }
    }

    printf("\nResult(Matrices): \n");
    for (i = 0; i < rowMatrix; i++) {
        for (j = 0; j < columnMatrix; j++) {
            matrixSumPerMatrix[i][j] = matrixOne[i][j] + matrixTwo[i][j];
        }
    }
    for (i = 0; i < rowMatrix; i++) {
        for (j = 0; j < columnMatrix; j++) {
            printf("%d\t", matrixSumPerMatrix[i][j]);
            if (j == rowMatrix - 1) {
                printf("\n");
            }
        }
    }

    printf("\nResult(Total): ");
    for (i = 0; i < rowMatrix; i++) {
        for (j = 0; j < columnMatrix; j++) {
            matrixTotal = matrixTotal + matrixSumPerMatrix[i][j];
        }
    }
    printf("%d", matrixTotal);

}

void TwoDimensionalArraysEx4() {

    int i, j;
    int rowPascal, pascalArray[128][128];

    printf("Enter the number of rows to be printed in the Pascal's Triangle: ");
    scanf("%d", &rowPascal);

    if (rowPascal > 0) {
        printf("\nResult:\n");
        for (i = 0; i < rowPascal; i++) {
            for (j = 0; j <= i; j++) {
                if (i == 0 || j == 0) {
                    pascalArray[i][j] = 1;
                }
                else {
                    pascalArray[i][j] = pascalArray[i - 1][j - 1] + pascalArray[i - 1][j];
                }

                printf("%d", pascalArray[i][j]);
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

    else if (rowPascal == 0) {
        printf("Unfortunately, the program cannot print empty rows. Try again.");
    }

    else {
        printf("Unfortunately, the program cannot print negative rows. Try again.");
    }
}

int main() {
    //TwoDimensionalArraysEx1();
    //TwoDimensionalArraysEx2();
    //TwoDimensionalArraysEx3();
    TwoDimensionalArraysEx4();
    return 0;

}