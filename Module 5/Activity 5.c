#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;

    struct node *leftBranch;
    struct node *rightBranch;
};

struct node *root = NULL;

void insertNode(int data) {
    struct node *tempNode = (struct node*) malloc(sizeof(struct node));
    struct node *currentBranch;
    struct node *headBranch;

    tempNode->data = data;
    tempNode->leftBranch = NULL;
    tempNode->rightBranch = NULL;

    if(root == NULL) {
        root = tempNode;
    }

    else {
        currentBranch = root;
        headBranch = NULL;

        while(1) {
            headBranch = currentBranch;
            if(data < headBranch->data) {
                currentBranch = currentBranch->leftBranch;

                if(currentBranch == NULL) {
                    headBranch->leftBranch = tempNode;
                    return;
                }
            }

            else {
                currentBranch = currentBranch->rightBranch;
                if(currentBranch == NULL) {
                    headBranch->rightBranch = tempNode;
                    return;
                }
            }
        }
    }
}

void preOrderTraversal(struct node* root) {
    if(root != NULL) {
        printf("%d ",root->data);
        preOrderTraversal(root->leftBranch);
        preOrderTraversal(root->rightBranch);
    }
}

void postOrderTraversal(struct node* root) {
    if(root != NULL) {
        postOrderTraversal(root->leftBranch);
        postOrderTraversal(root->rightBranch);
        printf("%d ", root->data);
    }
}

void inOrderTraversal(struct node* root) {
    if(root != NULL) {
        inOrderTraversal(root->leftBranch);
        printf("%d ",root->data);
        inOrderTraversal(root->rightBranch);
    }
}

void binaryTree() {
    int i, limitNode;
    int arrayNode[128];

    printf("Enter the limit for the node: ");
    scanf("%d", &limitNode);

    for(i = 0; i < limitNode; i++) {
        printf("Node [%d] = ", i);
        scanf("%d", &arrayNode[i]);
        insertNode(arrayNode[i]);
    }

    printf("\nPre-order traversal: ");
    preOrderTraversal(root);

    printf("\nPost-order traversal: ");
    postOrderTraversal(root);

    printf("\nInorder traversal: ");
    inOrderTraversal(root);

    printf("\n\n");
}

int main() {
    int option;
    binaryTree();

    for(;;) {
        printf("Do you want to continue? This will overwrite the memory and will not create a new one."
               "\n1 - Yes"
               "\n2 - No"
               "\nAnswer: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n\n");
                binaryTree();
                break;
            case 2:
                printf("Okay. Good bye.");
                return 0;
        }
    }
}