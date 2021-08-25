#include <stdio.h>

void ModuleTwoActivityTwo() {
    int i, j;
    int tempArray, numArray, insertArray, arrayEx[128];
    printf("Enter the number of elements to be entered in the array: ");
    scanf("%d", &numArray);

    printf("Enter the elements:\n");
    for (i = 0; i < numArray; i++) {
        printf("Element [%d] = ", i);
        scanf("%d", &arrayEx[i]);
    }

    printf("\nEnter the number to be inserted in the array: ");
    scanf("%d", &insertArray);

    for (i = numArray; i >= numArray; i--) {
        arrayEx[i] = arrayEx[i - 1];
    }
    arrayEx[numArray] = insertArray;

    printf("\nResult:");
    for (i = 0; i <= numArray; i++) {
        for (j = i + 1; j <= numArray; j++) {
            if (arrayEx[i] > arrayEx[j]) {
                tempArray = arrayEx[i];
                arrayEx[i] = arrayEx[j];
                arrayEx[j] = tempArray;
            }
        }
    }

    for (i = 0; i <= numArray; i++) {
        printf("\nElement [%d] = %d", i, arrayEx[i]);
    }
}

int main() {
    ModuleTwoActivityTwo();
    return 0;
}