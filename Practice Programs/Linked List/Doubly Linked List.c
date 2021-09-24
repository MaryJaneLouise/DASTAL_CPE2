#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main();

struct node {
    struct node *prevPointer;
    int data;
    struct node *nextPointer;
}*head, *tempNode1, *tempNode2, *tempNode3, *tempNode4;

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

void insertAtBeginning() {
    if (head == NULL) {
        printf("\nInserting a node in the beginning of the list");
        createList();
        printf("\n");
        head = tempNode1;
        tempNode2 = head;
    }

    else {
        printf("\nInserting a node in the beginning of the list");
        createList();
        printf("\n");
        tempNode1 -> nextPointer = head;
        head -> prevPointer = tempNode1;
        head = tempNode1;
    }
}

void insertAtEnd() {
    if (head == NULL) {
        printf("\nInserting a node in the end of the list");
        createList();
        printf("\n");
        head = tempNode1;
        tempNode2 = head;
    }

    else {
        printf("\nInserting a node in the end of the list");
        createList();
        printf("\n");
        tempNode2 -> nextPointer = tempNode1;
        tempNode1 -> prevPointer = tempNode2;
        tempNode2 = tempNode1;
    }
}

void showNode() {
    tempNode3 = head;

    if (tempNode3 == NULL) {
        printf("The list is empty.\n\n");
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

    for(;;) {
        printf("Hello there! What do you want to do?"
               "\n1 - Insert a node in the beginning of the list"
               "\n2 - Insert a node in the end of the list"
               "\n3 - "
               "\n4 - "
               "\n5 - Show the linked list"
               "\n6 - "
               "\n7 - "
               "\n8 - "
               "\n9 - "
               "\n10 - Exit"
               "\nAnswer: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insertAtBeginning();
                break;

            case 2:
                insertAtEnd();
                break;

            case 5:
                showNode();
                break;

            case 10:
                printf("Bye!");
                return 0;

            default:
                printf("It seems that you didn't enter a number that was given on the choices. "
                       "Please try again.\n\n");
                main();
        }
    }
}