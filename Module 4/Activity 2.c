#include <stdio.h>
#include <ctype.h>

float expressionConverted[128];
int top = -1;

void push(int tempStack) {
    expressionConverted[++top] = tempStack;
}

float pop() {
    return expressionConverted[top--];
}

int main() {
    char expressionPostFix[128];
    char *pointerPostFix;
    float digitOne, digitTwo, result;
    float tempNum;

    printf("Evaluating PostFix\n");
    printf("Enter the PostFix expression to be evaluated: ");
    scanf("%s", expressionPostFix);

    pointerPostFix = expressionPostFix;

    while (*pointerPostFix != '\0') {
        if (isdigit(*pointerPostFix)) {
            tempNum = *pointerPostFix - 48;
            push(tempNum);
        }

        else {
            digitOne = pop();
            digitTwo = pop();

            switch(*pointerPostFix) {
                case '+':
                    result = digitOne + digitTwo;
                    break;

                case '-':
                    result = digitTwo - digitOne;
                    break;

                case '*':
                    result = digitOne * digitTwo;
                    break;

                case '/':
                    if (digitOne == 0) {
                        printf("Sorry, we cannot continue since the divisor is 0. "
                               "Please try again.");
                    }
                    else {
                        result = digitTwo / digitOne;
                    }
                    break;
            }
            push(result);
        }
        pointerPostFix++;
    }
    printf("\nResult:\n%0.2f", pop());
    return 0;
}

