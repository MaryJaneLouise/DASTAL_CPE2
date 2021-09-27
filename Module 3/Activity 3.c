#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main();

struct node {
    struct node *prevPointer;
    int data;
    struct node *nextPointer;
}*head, *tempNode1, *tempNode2, *tempNode3;

int incrementNode = 0;

void createList() {
    int enterNode;

    tempNode1 = (struct node*) malloc(sizeof(struct node));
    tempNode1 -> prevPointer = NULL;
    tempNode1 -> nextPointer = NULL;

    printf("\nEnter the value to be entered in the node: ");
    scanf("%d", &enterNode);

    tempNode1 -> data = enterNode;
    incrementNode++;
}

void insertNode() {
    if (head == NULL) {
        printf("\nInserting a node in the list");
        createList();
        printf("\n");
        head = tempNode1;
        tempNode2 = head;
    }

    else {
        printf("\nInserting a node in the list");
        createList();
        printf("\n");
        tempNode1 -> nextPointer = head;
        head -> prevPointer = tempNode1;
        head = tempNode1;
    }
}

void deleteAtBeginning() {
    struct node *deletePointer;

    if (head == NULL) {
        printf("\nThe linked list is empty.");
        incrementNode = 0;
    }

    else if (head -> nextPointer == NULL) {
        head = NULL;
        free(head);
        printf("\nThe selected node was deleted.\n");
    }

    else {
        deletePointer = head;
        head = head -> nextPointer;
        head -> prevPointer = NULL;
        free(deletePointer);
        printf("\nThe selected node was deleted.\n");
    }

    incrementNode--;
}

void deleteAtEnd() {
    struct node *deletePointer;

    if (head == NULL) {
        printf("\nThe linked list is empty.");
        incrementNode = 0;
    }

    else if (head -> nextPointer == NULL) {
        head = NULL;
        free(head);
        printf("\nThe selected node was deleted.");
    }

    else {
        deletePointer = head;

        if (deletePointer -> nextPointer != NULL) {
            deletePointer = deletePointer -> nextPointer;
        }

        deletePointer -> prevPointer -> nextPointer = NULL;
        free(deletePointer);
        printf("\nThe selected node was deleted.\n");
    }
    incrementNode--;
}

void deleteAtAPosition() {
    int i = 1;
    int position;

    printf("\nEnter the position of the node to be deleted: ");
    scanf("%d", &position);
    tempNode3 = head;

    if ((position < 1) || (position >= incrementNode + 1)) {
        printf("\nThe entered position number is not found on the list.");
    }

    else if (head == NULL) {
        printf("\nThe linked list is empty.");
        incrementNode = 0;
    }

    else {
        while (i < position) {
            tempNode3 = tempNode3 -> nextPointer;
            i++;
        }

        if (i == 1) {
            if (tempNode3 -> nextPointer == NULL) {
                printf("\nThe selected node was deleted.\n");
                free(tempNode3);
                tempNode3 = head = NULL;
                return;
            }
        }

        if (tempNode3 -> nextPointer == NULL) {
            tempNode3 -> prevPointer -> nextPointer = NULL;
            free(tempNode3);
            printf("\nThe selected node was deleted.\n");
            return;
        }

        tempNode3 -> nextPointer -> prevPointer = tempNode3 -> prevPointer;

        if (i != 1) {
            tempNode3 -> prevPointer -> nextPointer = tempNode3 -> nextPointer;
        }

        if (i == 1) {
            head = tempNode3 -> nextPointer;
        }
        printf("\nThe selected node was deleted.\n");
        free(tempNode3);
    }

    incrementNode--;
}

void showNode() {
    tempNode3 = head;

    if (tempNode3 == NULL) {
        printf("The list is empty.\n\n");
        incrementNode = 0;
        main();
    }

    printf("\nThere are %d elements in the list:\n", incrementNode);

    while (tempNode3 -> nextPointer != NULL) {
        printf("• Node %d\n", tempNode3 -> data);
        tempNode3 = tempNode3 -> nextPointer;
    }

    printf("• Node %d\n", tempNode3 -> data);
    printf("\n");
}

int main() {
    int option;

    head = NULL;
    tempNode1 = NULL;
    tempNode2 = NULL;

    for (;;) {
        printf("Hello there! What do you want to do?"
               "\n1 - Insert a node in the list"
               "\n2 - Delete a node in the beginning of the list"
               "\n3 - Delete a node in the end of the list"
               "\n4 - Delete a node at a selected pointer"
               "\n5 - Exit the program"
               "\nAnswer: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insertNode();
                showNode();
                break;

            case 2:
                deleteAtBeginning();
                showNode();
                break;

            case 3:
                deleteAtEnd();
                showNode();
                break;

            case 4:
                deleteAtAPosition();
                showNode();
                break;

            case 5:
                printf("Bye!");
                return 0;

            default:
                printf("It seems that you didn't enter a number that was given on the choices. "
                       "Please try again.\n\n");
                main();
        }
    }
}

