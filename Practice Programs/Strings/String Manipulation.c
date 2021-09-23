#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

void StringManipulationEx1() {
    int i, j;
    int option;

    //word or phrase
    int tempChar[128];
    char phraseOrWord[128];
    //Name
    char firstName[128], middleName[128], lastName[128];

    printf("Character to ASCII converter");
    printf("\nWhat do you want to convert?"
           "\n1 - I want to convert a word or phrase"
           "\n2 - I want to convert a name"
           "\nAnswer: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("\nEnter the word or phrase you want to convert:\n");
            scanf("%s", phraseOrWord);

            printf("Result:");
            i = 0;
            while (phraseOrWord[i] != '\0') {
                tempChar[i] = phraseOrWord[i];
                i++;
            }

            for (j = 0; j < i; j++) {
                if (phraseOrWord[i] == " " || phraseOrWord[i] == "-" || phraseOrWord[i] == "_") {
                    printf("• space = 32");
                }
                printf("\n• %c = %d", phraseOrWord[j], tempChar[j]);
            }
            break;

        case 2:
            printf("\nEnter the following details:\n");
            printf("\nIf you have many first name (e. g Mary Jane Louise), write it as:\n");
            printf("Mary-Jane-Louise\n");
            printf("First Name = ");
            scanf("%s", firstName);

            printf("\nIf you don't have a middle name, type 'none' without quotation marks and disregard the converted ASCII for 'none'.");
            printf("\nMiddle Name = ");
            scanf("%s", middleName);

            printf("\nIf you don't have a last name, type 'none' without quotation marks and disregard the converted ASCII for 'none'.");
            printf("\nLast Name = ");
            scanf("%s", lastName);

            printf("\n");

            printf("\nFull Name converted to ASCII code:\n");
            for (i = 0; firstName[i] != '\0'; i++ ) {
                if (firstName[i] == '-' || firstName[i] == 45 || firstName[i] == '_' || firstName[i] == 95) {
                    printf("• <space> = 32 not ");
                }
                printf("• %c = %d\n", firstName[i], firstName[i]);
            }

            printf("• <space> = 32\n");

            for (i = 0; middleName[i] != '\0'; i++ ) {
                if (middleName[i] == '-' || middleName[i] == 45 || middleName[i] == '_' || middleName[i] == 95) {
                    printf("• <space> = 32 not ");
                }
                printf("• %c = %d\n", middleName[i], middleName[i]);
            }

            printf("• <space> = 32\n");

            for (i = 0; lastName[i] != '\0'; i++ ) {
                if (lastName[i] == '-' || lastName[i] == 45 || lastName[i] == '_' || lastName[i] == 95) {
                    printf("• <space> = 32 not ");
                }
                printf("• %c = %d\n", lastName[i], lastName[i]);
            }
            break;
    }

}

int main() {
    StringManipulationEx1();
    return 0;
}

