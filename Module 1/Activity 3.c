#include <stdlib.h>
#include <stdio.h>

void ModuleOneActivityThree() {
    int i, j;
    int arrayEx[128], limitArray, deleteNumArray, tempArray;
    int indexArray = -1;

    printf("Enter the number of elements to be entered: ");
    scanf("%d", &limitArray);

    printf("Enter the elements below:\n");
    for (i = 0; i < limitArray; i++) {
        printf("Element [%d] = ", i);
        scanf("%d", &arrayEx[i]);
    }

    printf("\nEnter the number to be deleted in the array: ");
    scanf("%d", &deleteNumArray);
    for (i = 0; i < limitArray; i++) {
        if (arrayEx[i] == deleteNumArray) {
            indexArray = i;
        }
    }

    if (indexArray != -1) {
        for (i = indexArray; i < limitArray - 1; i++) {
            arrayEx[i] = arrayEx[i + 1];
        }

        printf("\nResult:");
        for (i = 0; i < limitArray - 1; i++) {
            for (j = i + 1; j < limitArray - 1; j++) {
                if (arrayEx[i] > arrayEx[j]) {
                    tempArray = arrayEx[i];
                    arrayEx[i] = arrayEx[j];
                    arrayEx[j] = tempArray;
                }
            }
        }

        for (i = 0; i < limitArray - 1; i++) {
            printf("\nElement [%d] = %d", i, arrayEx[i]);
        }
    }

    else {
        printf("The element that was entered by the user was not found in the array.");
    }
}

int main() {
    ModuleOneActivityThree();
    return 0;
}

