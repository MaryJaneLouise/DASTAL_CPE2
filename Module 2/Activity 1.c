#include <stdio.h>

void ModuleTwoActivityOne() {
    int i;
    int arrayEx[7] = {1, 2, 3, 4, 5, 6, 7};
    int *pointerArray;

    /*printf("The elements found at the original array is:");
    for (i = 0; i < 7; i++) {
        printf("\nOriginal Array | Element [%d] = %d", i, arrayEx[i]);
    }*/

    pointerArray = arrayEx;

    printf("The elements found at the pointer is:");
    for (i = 0; i < 7; i++) {
        printf("\nPointer Array | Element [%d] = %d", i, *pointerArray);
        pointerArray++;
    }
}

int main() {
    ModuleTwoActivityOne();
    return 0;
}