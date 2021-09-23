#include <stdio.h>
#include <stdlib.h>

int main();

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
int incrementNode = 0;

void insertAtBeginning(int nodeEnter) {
    struct node *nodeFinal;

    nodeFinal = (struct node*) malloc(sizeof(struct node));
    nodeFinal -> data = nodeEnter;
    incrementNode++;

    if (start == NULL) {
        start = nodeFinal;
        start -> next = NULL;
    }

    nodeFinal -> next = start;
    start = nodeFinal;
}

void insertAtEnd(int nodeEnter) {
    struct node *nodeFinal, *tempNode;

    nodeFinal = (struct node*) malloc(sizeof(struct node));
    nodeFinal -> data = nodeEnter;
    incrementNode++;

    if (start == NULL) {
        start = nodeFinal;
        start -> next = NULL;
        return;
    }

    tempNode = start;

    while (tempNode -> next != NULL) {
        tempNode = tempNode -> next;
    }

    tempNode -> next = nodeFinal;
    nodeFinal -> next = NULL;
}

void showNode() {
    struct node *nodeFinal;

    nodeFinal = start;

    if (nodeFinal == NULL) {
        printf("The linked list is empty.\n\n");
        main();
    }

    printf("\nThere are %d elements in linked list.\n", incrementNode);

    while (nodeFinal -> next != NULL) {
        printf("• Node = %d\n", nodeFinal -> data);
        nodeFinal = nodeFinal -> next;
    }

    printf("• Node = %d\n", nodeFinal -> data);
}

int main() {
    int option;
    int nodeEnter;

    for (;;) {
        printf("Hello there! What do you want to do?"
               "\n1) Insert a node at the beginning of the linked list"
               "\n2) Insert a node at the end of the linked list"
               "\n3) Show the linked list"
               "\n4) Close the program"
               "\nAnswer: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nInserting node in the beginning of the linked list"
                       "\nEnter the value of the node to be entered in the linked list: ");
                scanf("%d", &nodeEnter);
                insertAtBeginning(nodeEnter);
                printf("\n");
                break;

            case 2:
                printf("\nInserting node in the end of the linked list"
                       "\nEnter the value of the node to be entered in the linked list: ");
                scanf("%d", &nodeEnter);
                insertAtEnd(nodeEnter);
                printf("\n");
                break;

            case 3:
                showNode();
                printf("\n");
                break;

            case 4:
                printf("\nThe program now will be closed. Bye!");
                return 0;

            default:
                printf("It seems that you didn't enter a number that was given on the choices. "
                       "Please try again.");
                main();
        }
    }
}