#include <stdio.h>
#include <stdlib.h>

void ModuleOneActivityFour() {
    int i, j, k;
    int tempArray, numFirstArray, numSecondArray, arrayFirst[128], arraySecond[128], finalArray[128];
    int deleteNumArray, indexArray = -1;
    printf("Enter the number of elements to be entered in the first array: ");
    scanf("%d", &numFirstArray);

    printf("Enter the elements:\n");
    for (i = 0; i < numFirstArray; i++) {
        printf("1st Array | Element [%d] = ", i);
        scanf("%d", &arrayFirst[i]);
        finalArray[i] = arrayFirst[i];
    }

    j = i;

    printf("\nEnter the number of elements to be entered in the second array: ");
    scanf("%d", &numSecondArray);

    printf("Enter the elements:\n");
    for (i = 0; i < numSecondArray; i++) {
        printf("2nd Array | Element [%d] = ", i);
        scanf("%d", &arraySecond[i]);
        finalArray[j] = arraySecond[i];
        j++;
    }

    printf("\nEnter the number to be deleted in the array: ");
    scanf("%d", &deleteNumArray);
    for (i = 0; i < (numFirstArray + numSecondArray); i++) {
        if (finalArray[i] == deleteNumArray) {
            indexArray = i;
        }
    }

    if (indexArray != -1) {
        /*printf("\nResult of the unsorted merged arrays:\n");
        for (i = 0; i < j - 1; i++) {
            printf("Element [%d] = %d\n", i, finalArray[i]);
        }*/

        for (i = indexArray; i < (numFirstArray + numSecondArray) - 1; i++) {
            finalArray[i] = finalArray[i + 1];
        }

        for (i = 0; i < (numFirstArray + numSecondArray) - 1; i++) {
            for (k = i + 1; k < (numFirstArray + numSecondArray) - 1; k++) {
                if (finalArray[i] > finalArray[k]) {
                    tempArray = finalArray[i];
                    finalArray[i] = finalArray[k];
                    finalArray[k] = tempArray;
                }
            }
        }
        printf("\nResult:\n");
        for (i = 0; i < j - 1; i++) {
            printf("Element [%d] = %d\n", i, finalArray[i]);
        }
    }

    else {
        printf("The entered number was not found in the array. Try again.");
    }
}

int main() {
    ModuleOneActivityFour();
    return 0;
}

