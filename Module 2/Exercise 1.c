#include <stdio.h>
#include <stdlib.h>

void Module2ExerciseOne() {
    int i, j;
    int option;
    int rowMatrix, columnMatrix;

    //Example 1 & 2
    int matrixEx[128][128], matrixTranspose[128][128];
    //Example 3
    int matrixOne[128][128], matrixTwo[128][128], matrixSumPerMatrix[128][128], matrixTotal;

    printf("Hello there! What do you want to do?\n"
           "1 - Read only the matrix after entering them\n"
           "2 - Transposing the matrix into other position\n"
           "3 - Find the two sum of two matrices\nAnswer: ");
    scanf("%d", &option);
    printf("\n");

    //Choices

    switch (option) {
        case 1:
            printf("\nRead and displaying a n x n matrix\n");
            printf("Enter the number of rows of the array: ");
            scanf("%d", &rowMatrix);

            printf("Enter the number of columns of the array: ");
            scanf("%d", &columnMatrix);

            if (rowMatrix <= 0 || columnMatrix <= 0) {
                if (rowMatrix == 0) {
                    printf("\nResult:\nYou know that you cannot print empty rows right?");
                }
                else if (rowMatrix < 0) {
                    printf("\nResult:\nYou know that you cannot print negative rows right?");
                }
                else if (columnMatrix == 0) {
                    printf("\nResult:\nYou know that you cannot print empty column right?");
                }
                else if (columnMatrix < 0) {
                    printf("\nResult:\nYou know that you cannot print negative rows right?");
                }

            }
            else {
                printf("\nEnter the elements for the array:\n");
                for (i = 0; i < rowMatrix; i++) {
                    for (j = 0; j < columnMatrix; j++) {
                        printf("Element [%d][%d] = ", i, j);
                        scanf("%d", &matrixEx[i][j]);
                    }
                }

                printf("\nResult:\n");
                for (i = 0; i < rowMatrix; i++) {
                    for (j = 0; j < columnMatrix; j++) {
                        printf("%d\t", matrixEx[i][j]);
                        if (rowMatrix > columnMatrix) {
                            if (rowMatrix - columnMatrix == 1) {
                                if (j == rowMatrix - 2) {
                                    printf("\n");
                                }
                            }
                            else if (rowMatrix - columnMatrix == 2) {
                                if (j == rowMatrix - 3) {
                                    printf("\n");
                                }
                            }
                        }
                        else if (rowMatrix == columnMatrix) {
                            if (j == rowMatrix - 1) {
                                printf("\n");
                            }
                        }
                        else if (rowMatrix < columnMatrix){
                            if (columnMatrix - rowMatrix == 1) {
                                if (j == rowMatrix) {
                                    printf("\n");
                                }
                            }
                            else if (columnMatrix - rowMatrix == 2) {
                                if (j == rowMatrix + 1) {
                                    printf("\n");
                                }
                            }
                        }
                    }
                }
            }
            break;

        case 2:
            printf("\nTransposing a n x n matrix\n");
            printf("Enter the number of rows of the array: ");
            scanf("%d", &rowMatrix);

            printf("Enter the number of columns of the array: ");
            scanf("%d", &columnMatrix);

            if (rowMatrix <= 0 || columnMatrix <= 0) {
                if (rowMatrix == 0) {
                    printf("\nResult:\nYou know that you cannot print empty rows right?");
                }
                else if (rowMatrix < 0) {
                    printf("\nResult:\nYou know that you cannot print negative rows right?");
                }
                else if (columnMatrix == 0) {
                    printf("\nResult:\nYou know that you cannot print empty column right?");
                }
                else if (columnMatrix < 0) {
                    printf("\nResult:\nYou know that you cannot print negative rows right?");
                }

            }
            else {
                printf("\nEnter the elements for the array:\n");
                for (i = 0; i < rowMatrix; i++) {
                    for (j = 0; j < columnMatrix; j++) {
                        printf("Element [%d][%d] = ", i, j);
                        scanf("%d", &matrixEx[i][j]);
                        matrixTranspose[i][j] = matrixEx[j][i];
                    }
                }

                for (i = 0; i < rowMatrix; i++) {
                    for (j = 0; j < columnMatrix; j++) {
                        matrixTranspose[j][i] = matrixEx[i][j];
                    }
                }

                printf("\nOriginal Matrix:\n");
                for (i = 0; i < rowMatrix; i++) {
                    for (j = 0; j < columnMatrix; j++) {
                        printf("%d\t", matrixEx[i][j]);
                        if (rowMatrix > columnMatrix) {
                            if (rowMatrix - columnMatrix == 1) {
                                if (j == rowMatrix - 2) {
                                    printf("\n");
                                }
                            }
                            else if (rowMatrix - columnMatrix == 2) {
                                if (j == rowMatrix - 3) {
                                    printf("\n");
                                }
                            }
                        }
                        else if (rowMatrix == columnMatrix) {
                            if (j == rowMatrix - 1) {
                                printf("\n");
                            }
                        }
                        else if (rowMatrix < columnMatrix){
                            if (columnMatrix - rowMatrix == 1) {
                                if (j == rowMatrix) {
                                    printf("\n");
                                }
                            }
                            else if (columnMatrix - rowMatrix == 2) {
                                if (j == rowMatrix + 1) {
                                    printf("\n");
                                }
                            }
                        }
                    }
                }

                printf("\nTransposed Matrix:\n");
                for (i = 0; i < columnMatrix; i++) {
                    for (j = 0; j < rowMatrix; j++) {
                        printf("%d\t", matrixTranspose[i][j]);
                        if (j == rowMatrix - 1) {
                            printf("\n");
                        }
                    }
                }
            }
            break;

        case 3:
            printf("Enter the number of rows for the two matrices: ");
            scanf("%d", &rowMatrix);

            printf("Enter the number of columns for the two matrices: ");
            scanf("%d", &columnMatrix);

            if (rowMatrix <= 0 || columnMatrix <= 0) {
                if (rowMatrix == 0) {
                    printf("\nResult:\nYou know that you cannot print empty rows right?");
                }
                else if (rowMatrix < 0) {
                    printf("\nResult:\nYou know that you cannot print negative rows right?");
                }
                else if (columnMatrix == 0) {
                    printf("\nResult:\nYou know that you cannot print empty column right?");
                }
                else if (columnMatrix < 0) {
                    printf("\nResult:\nYou know that you cannot print negative rows right?");
                }

            }
            else {
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
                        if (rowMatrix > columnMatrix) {
                            if (rowMatrix - columnMatrix == 1) {
                                if (j == rowMatrix - 2) {
                                    printf("\n");
                                }
                            }
                            else if (rowMatrix - columnMatrix == 2) {
                                if (j == rowMatrix - 3) {
                                    printf("\n");
                                }
                            }
                        }
                        else if (rowMatrix == columnMatrix) {
                            if (j == rowMatrix - 1) {
                                printf("\n");
                            }
                        }
                        else if (rowMatrix < columnMatrix){
                            if (columnMatrix - rowMatrix == 1) {
                                if (j == rowMatrix) {
                                    printf("\n");
                                }
                            }
                            else if (columnMatrix - rowMatrix == 2) {
                                if (j == rowMatrix + 1) {
                                    printf("\n");
                                }
                            }
                        }
                    }
                }

                printf("\nSecond Matrix:\n");
                for (i = 0; i < rowMatrix; i++) {
                    for (j = 0; j < columnMatrix; j++) {
                        printf("%d\t", matrixTwo[i][j]);
                        if (rowMatrix > columnMatrix) {
                            if (rowMatrix - columnMatrix == 1) {
                                if (j == rowMatrix - 2) {
                                    printf("\n");
                                }
                            }
                            else if (rowMatrix - columnMatrix == 2) {
                                if (j == rowMatrix - 3) {
                                    printf("\n");
                                }
                            }
                        }
                        else if (rowMatrix == columnMatrix) {
                            if (j == rowMatrix - 1) {
                                printf("\n");
                            }
                        }
                        else if (rowMatrix < columnMatrix){
                            if (columnMatrix - rowMatrix == 1) {
                                if (j == rowMatrix) {
                                    printf("\n");
                                }
                            }
                            else if (columnMatrix - rowMatrix == 2) {
                                if (j == rowMatrix + 1) {
                                    printf("\n");
                                }
                            }
                        }
                    }
                }

                printf("\nSolution:\n");
                for (i = 0; i < rowMatrix; i++) {
                    for (j = 0; j < columnMatrix; j++) {
                        printf("(%d + %d)\t", matrixOne[i][j], matrixTwo[i][j]);
                        if (rowMatrix > columnMatrix) {
                            if (rowMatrix - columnMatrix == 1) {
                                if (j == rowMatrix - 2) {
                                    printf("\n");
                                }
                            }
                            else if (rowMatrix - columnMatrix == 2) {
                                if (j == rowMatrix - 3) {
                                    printf("\n");
                                }
                            }
                        }
                        else if (rowMatrix == columnMatrix) {
                            if (j == rowMatrix - 1) {
                                printf("\n");
                            }
                        }
                        else if (rowMatrix < columnMatrix){
                            if (columnMatrix - rowMatrix == 1) {
                                if (j == rowMatrix) {
                                    printf("\n");
                                }
                            }
                            else if (columnMatrix - rowMatrix == 2) {
                                if (j == rowMatrix + 1) {
                                    printf("\n");
                                }
                            }
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
                        if (rowMatrix > columnMatrix) {
                            if (rowMatrix - columnMatrix == 1) {
                                if (j == rowMatrix - 2) {
                                    printf("\n");
                                }
                            }
                            else if (rowMatrix - columnMatrix == 2) {
                                if (j == rowMatrix - 3) {
                                    printf("\n");
                                }
                            }
                        }
                        else if (rowMatrix == columnMatrix) {
                            if (j == rowMatrix - 1) {
                                printf("\n");
                            }
                        }
                        else if (rowMatrix < columnMatrix){
                            if (columnMatrix - rowMatrix == 1) {
                                if (j == rowMatrix) {
                                    printf("\n");
                                }
                            }
                            else if (columnMatrix - rowMatrix == 2) {
                                if (j == rowMatrix + 1) {
                                    printf("\n");
                                }
                            }
                        }
                    }
                }

                printf("\nResult(Total): ");
                for (i = 0; i < rowMatrix; i++) {
                    for (j = 0; j < columnMatrix; j++) {
                        matrixTotal = matrixTotal + matrixSumPerMatrix[i][j];
                    }
                }
                printf("%d\n", matrixTotal);
            }
            break;

        default:
            printf("You entered a number that is not on the list of options. "
                   "Fortunately, you have still a chance to restart the program.\n");
            break;
    }
}

void optionGoBack(int goBack) {
    printf("\n\nDo you want to try again?"
           "\n1 - Yes"
           "\n2 - No"
           "\nAnswer: ");
    scanf("%d", &goBack);
    if (goBack == 1) {
        printf("\n\n");
        Module2ExerciseOne();
    }
    else if (goBack == 2) {
        printf("The program is closing. Good day!");
    }
    else {
        printf("You entered a number that was not in the options. Still, the program will close. Good day.");
    }
}

int main() {
    Module2ExerciseOne();

    int goBack;
    printf("\n\nDo you want to try again?"
           "\n1 - Yes"
           "\n2 - No"
           "\nAnswer: ");
    scanf("%d", &goBack);
    optionGoBack(goBack);
    return 0;
}
