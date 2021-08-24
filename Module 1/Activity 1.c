#include <stdio.h>

void ModuleOneExercise1() {
    int i;
    int arrayExample[10] = {1000, 1002, 1004, 1006, 1008, 1010, 1012, 1014};

    for (i = 0; i < 10; i++) {
        printf("Element [%d] = %d\n", i, arrayExample[i]);
    }
}

void ModuleOneExercise2() {
    int i;
    int arrayExample[10] = {1000, 1002, 1004, 1006, 1008, 1010, 1012, 1014};

    for (i = 0; i < 10; i++) {
        printf("'marks' is at address %p\n", arrayExample[i]);
    }
}

void ModuleOneExercise3() {
    int i, limitArray;
    int arrayExample[128];

    printf("Enter the limit of the array: ");
    scanf("%d", &limitArray);
    printf("\nEnter the elements of the array:\n");

    for (i = 0; i < limitArray; i++) {
        printf("Element [%d] = ", i);
        scanf("%d", &arrayExample[i]);
    }

    printf("\nResult:");
    for (i = 0; i < limitArray; i++) {
        printf("\nElement [%d / %p] = %d", i, arrayExample[i], arrayExample[i]);
    }
}

void ModuleOneExercise4() {
    int i, limitArray, sumArray = 0;
    int arrayExample[128];

    printf("Enter the limit of the array: ");
    scanf("%d", &limitArray);
    printf("Enter the elements of the array:\n");

    for (i = 0; i < limitArray; i++) {
        printf("Element [%d] = ", i);
        scanf("%d", &arrayExample[i]);
    }

    printf("\nSolution:\n");
    for (i = 0; i < limitArray; i++) {
        sumArray = sumArray + arrayExample[i];
    }
    for (i = 0; i < limitArray; i++) {
        printf("%d", arrayExample[i]);
        if (limitArray - i > 1) {
            printf(" + ");
        }
        else {
            printf(" = ");
        }
    }
    printf("%d", sumArray);
    printf("\nThe sum of the array is %d.", sumArray);
}
int main() {
    //ModuleOneExercise1();
    //ModuleOneExercise2();
    //ModuleOneExercise3();
    ModuleOneExercise4();
    return 0;
}
