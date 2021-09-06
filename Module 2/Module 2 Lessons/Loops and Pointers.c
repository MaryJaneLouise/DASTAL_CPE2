#include <stdio.h>

void LoopsAndPointersEx1() {
    int i;
    int *pointerArray;
    int arrayEx[] = {1, 2, 3, 4, 5};

    *pointerArray = -1;
    *(pointerArray + 1) = 0;
    *(pointerArray - 1) = 1;

    printf("The array is:\n");
    for(i = 0; i < 5; i++) {
        printf("%d ", *(arrayEx + 1));
    }
}

void LoopsAndPointersEx2() {
    int i;
    int *pointerArrayOne, *pointerArrayTwo;
    int arrayEx[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    pointerArrayOne = arrayEx;
    pointerArrayTwo = arrayEx + 2;

    printf("The array is:\n");
    printf("%d", pointerArrayTwo - pointerArrayOne);
}

void LoopsAndPointersEx3() {
    int *pointerArrayOne, *pointerArrayTwo;
    int arrayEx[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    pointerArrayOne = arrayEx;
    pointerArrayTwo = &arrayEx[8];

    printf("The array is:\n");
    while (pointerArrayOne <= pointerArrayTwo) {
        printf("%d", *pointerArrayOne);
        pointerArrayOne++;
    }
}

void LoopsAndPointersEx4() {
    int i;
    int arrayEx[128], *pointerArray, limitArray;

    printf("Enter the number of elements to be entered in the array: ");
    scanf("%d", &limitArray);

    printf("\nEnter the elements:\n");
    for (i = 0; i < limitArray; i++) {
        printf("Original Array | Element [%d] = ", i);
        scanf("%d", &arrayEx[i]);
    }

    pointerArray = arrayEx;

    printf("\nThe elements found at the pointer is:");
    for (i = 0; i < limitArray; i++) {
        printf("\nPointer Array | Element [%d] = %d", i, *pointerArray);
        pointerArray++;
    }
}

int main() {
    //LoopsAndPointersEx1();
    //LoopsAndPointersEx2();
    //LoopsAndPointersEx3();
    LoopsAndPointersEx4();
    return 0;
}