#include <stdio.h>
#include <stdlib.h>

#define maxSizeQueue 128
int frontQueue = -1, rearQueue = -1;
int initiateQueue[maxSizeQueue];


void insertElements() {
    int insertItem;
    printf("\nInserting element at the queue\n");

    if (rearQueue == maxSizeQueue - 1) {
        printf("The queue is currently 'overflow'.\n\n");
    }
    else {
        if (frontQueue == -1) {
            frontQueue = 0;
        }
        printf("Enter the any element to be entered in the queue: ");
        scanf("%d", &insertItem);
        rearQueue = rearQueue + 1;
        initiateQueue[rearQueue] = insertItem;
        printf("\n\n");

    }
}

void deleteElements() {
    printf("\nDeleting an element in the queue\n");

    if (frontQueue == -1 || frontQueue > rearQueue) {
        printf("The queue is currently 'overflow'.\n\n");
    }
    else {
        printf("Element %d has been deleted from the queue.", initiateQueue[frontQueue]);
        frontQueue = frontQueue + 1;
        printf("\n\n");
    }
}

void showElements() {
    int i;

    if (frontQueue == -1 || frontQueue > rearQueue) {
        printf("The queue is currently empty. "
               "Please add some elements first before clicking this option.\n\n");
    }
    else {
        printf("\nElements of the queue as of now:\n");

        for (i = frontQueue; i <= rearQueue; i++) {
            printf("Element [%d] = %d\n", i, initiateQueue[i]);
        }
        printf("\n\n");
    }
}

int main() {
    int optionPick;

    for(;;) {
        printf("Choose an option:"
               "\n1) Insert an element to the queue"
               "\n2) Delete an element to the queue"
               "\n3) Display all of the contents of the queue as of now"
               "\n4) Exit the program"
               "\nAnswer: ");
        scanf("%d", &optionPick);

        switch (optionPick) {
            case 1:
                insertElements();
                break;

            case 2:
                deleteElements();
                break;

            case 3:
                showElements();
                break;

            case 4:
                printf("Bye!");
                return 0;

            default:
                printf("The number you entered is not part of the options. "
                       "Please check the number and try again.");
        }
    }
}
