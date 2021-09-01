#include <stdio.h>
#include <stdlib.h>

void ModuleOneMergArr() {
    int i, j, k;
    int tempArray, numFirstArray, numSecondArray, arrayFirst[128], arraySecond[128], finalArray[128];
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

    printf("\nResult of the unsorted merged arrays:\n");
    for (i = 0; i < j; i++) {
        printf("Element [%d] = %d\n", i, finalArray[i]);
    }

    for (i = 0; i < (numFirstArray + numSecondArray); i++) {
        for (k = i + 1; k < (numFirstArray + numSecondArray); k++) {
            if (finalArray[i] > finalArray[k]) {
                tempArray = finalArray[i];
                finalArray[i] = finalArray[k];
                finalArray[k] = tempArray;
            }
        }
    }
    printf("\nResult of the sorted merged arrays:\n");
    for (i = 0; i < j; i++) {
        printf("Element [%d] = %d\n", i, finalArray[i]);
    }
}

int main() {
    ModuleOneMergArr();
    return 0;
}


