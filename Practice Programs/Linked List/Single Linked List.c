#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Sir's example
/*struct node {
    int data;
    struct node *next;
}*temp, *head;

void nodeInsertAtBeginning(int nodeEnter) {
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = nodeEnter;
    temp -> next = head;
    head = temp;
}

void printNode() {
    temp = head;
    printf("The element/s in the list: ");

    while (temp != NULL) {
        printf("\n• %d", temp -> data);
        temp = temp -> next;
    }
}
void main() {
    int i;
    int nodeEnter, limitList;

    printf("Enter the limit of the list: ");
    scanf("%d", &limitList);

    for (i = 0; i < limitList; i++) {
        printf("\nEnter value: ");
        scanf("%d", &nodeEnter);
        nodeInsertAtBeginning(nodeEnter);
        printNode();
    }
}*/


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

void deleteNodeInBeginning() {
    struct node *nodeFinal;
    int nodeRemove;

    if (start == NULL) {
        printf("Linked list is empty.");
    }

    nodeRemove = start -> data;
    nodeFinal = start -> next;
    free(start);
    start = nodeFinal;
    incrementNode--;

    printf("The node %d from the beginning of the linked list has been removed.", nodeRemove);
}

void deleteNodeInEnd() {
    struct node *nodeFinal, *nodeTemp;
    int nodeRemove;

    if (start == NULL) {
        printf("Linked list is empty.");
    }

    incrementNode--;

    if (start -> next == NULL) {
        nodeRemove = start -> data;
        free(start);
        start = NULL;
        printf("The node %d from the end of the linked list has been removed.", nodeRemove);
    }

    nodeFinal = start;

    while (nodeFinal -> next != NULL) {
        nodeTemp = nodeFinal;
        nodeFinal = nodeFinal -> next;
    }

    nodeRemove = nodeFinal -> data;
    nodeTemp -> next = NULL;
    free(nodeFinal);

    printf("The node %d from the end of the linked list has been removed.", nodeRemove);
}

void showNode() {
    struct node *nodeFinal;

    nodeFinal = start;

    if (nodeFinal == NULL) {
        printf("The linked list is empty.");
    }

    printf("\nThere are %d elements in linked list.\n", incrementNode);

    while (nodeFinal -> next != NULL) {
        printf("%d\n", nodeFinal -> data);
        nodeFinal = nodeFinal -> next;
    }

    printf("%d\n", nodeFinal -> data);
}

int main() {
    int option;
    int nodeEnter;

    printf("\nHello there!\n");
    for (;;) {
        printf("\nWhat do you want to do?"
               "\n1) Insert element at the beginning of the linked list"
               "\n2) Insert element at the end of the linked list"
               "\n3) Delete element at the beginning of the linked list"
               "\n4) Delete element at the end of the linked list"
               "\n5) Show the linked list"
               "\n6) Close the program"
               "\nAnswer: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the value of the node: ");
                scanf("%d", &nodeEnter);
                insertAtBeginning(nodeEnter);
                break;

            case 2:
                printf("Enter the value of the node: ");
                scanf("%d", &nodeEnter);
                insertAtEnd(nodeEnter);
                break;

            case 3:
                deleteNodeInBeginning();
                break;

            case 4:
                deleteNodeInEnd();
                break;

            case 5:
                showNode();
                break;

            case 6:
                printf("The program now will be closed. Bye!");
                return 0;

            default:
                printf("It seems that you didn't enter a number that was given on the choices. "
                       "Please try again.");
                main();
        }
    }
}

