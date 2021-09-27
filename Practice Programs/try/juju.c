#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head;

void createList(int n);
void insertNodeEnd(int data);
void displayList();


int main() {
    int n, data;
    printf("Please enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list: ");
    displayList();

    printf("\nPlease enter data to insert at the end of the list: ");
    scanf("%d", &data);
    insertNodeEnd(data);

    printf("\nData in the list: ");
    displayList();

    return 0;
}

void createList(int n) {
    struct node *newNode, *temp;
    int data, i;

    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Sorry, unable to allocate memory.");
    }
    else {
        printf("Please enter the data of Node 1: ");
        scanf("%d", &data);

        head -> data = data;
        head -> next = NULL;

        temp = head;

        for(i = 2; i <= n; i++) {
            newNode = (struct node*)malloc(sizeof(struct node));
            if(newNode == NULL) {
                printf("Sorry, unable to allocate memory.");
            }
            else {
                printf("Please enter the data of Node %d: ", i);
                scanf("%d", &data);

                newNode->data = data;
                newNode->next = NULL;

                temp->next = newNode;
                temp = temp->next;
            }
        }
        printf("Singly Linked List created successfully.");
    }
}

void insertNodeEnd(int data) {
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL) {
        printf("Sorry, unable to allocate memory.");
    }
    else {
        newNode->data = data;
        newNode->next = NULL;
        temp = head;

        while(temp != NULL && temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        printf("Data inserted successfully.");
    }
}

void displayList() {
    struct node *temp;
    if(head == NULL) {
        printf("The list is empty.");
    }
    else {
        temp = head;
        while(temp != NULL) {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
    }
}
