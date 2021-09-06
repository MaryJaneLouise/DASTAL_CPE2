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

int main() {
    //LoopsAndPointersEx1();
    //LoopsAndPointersEx2();
    LoopsAndPointersEx3();
    return 0;
}