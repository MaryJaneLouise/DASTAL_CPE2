#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char tempStack) {
    stack[++top] = tempStack;
}

char pop() {
    if(top == -1){
        return -1;
    }

    else {
        return stack[top--];
    }
}

int convertPostFix(char tempStack)
{
    if(tempStack == '(') {
        return 0;
    }
    if(tempStack == '+' || tempStack == '-') {
        return 1;
    }
    if(tempStack == '*' || tempStack == '/') {
        return 2;
    }
    return 0;
}

int main() {
    char expressionConvert[100];
    char *pointerStack, tempStack;

    printf("Infix to PostFix\nEnter the expression that you want to convert: ");
    scanf("%s",expressionConvert);
    printf("\n");
    pointerStack = expressionConvert;

    printf("Result of conversion:\n");
    while(*pointerStack != '\0')
    {
        if(isalnum(*pointerStack)) {
            printf("%c",*pointerStack);
        }
        else if(*pointerStack == '(') {
            push(*pointerStack);
        }

        else if(*pointerStack == ')') {
            while((tempStack = pop()) != '(') {
                printf("%c", tempStack);
            }
        }
        else {
            while(convertPostFix(stack[top]) >= convertPostFix(*pointerStack)) {
                printf("%c",pop());
            }
            push(*pointerStack);
        }
        pointerStack++;
    }

    while(top != -1) {
        printf("%c",pop());
    }
    return 0;
}