#include <stdio.h>
#include <stdlib.h>

void ModuleOneActivityFour() {
    int i, j;
    int tempArray, numArray, arrayEx[128];
    printf("Enter the number of elements to be entered in the array: ");
    scanf("%d", &numArray);

    printf("Enter the elements:\n");
    for (i = 0; i < numArray; i++) {
        printf("Element [%d] = ", i);
        scanf("%d", &arrayEx[i]);
    }
}

int main() {
    ModuleOneActivityFour();
    return 0;
}

