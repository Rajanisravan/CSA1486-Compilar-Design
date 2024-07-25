
#include <stdio.h>
#include <ctype.h>

#define MAX_ID_LENGTH 100

int isValidIdentifier(char *id) {
    int length = 0;
    char c;

    // Check if the first character is a letter or underscore
    if (!isalpha(id[0]) && id[0] != '_') {
        return 0;
    }

    // Check the rest of the characters
    while ((c = id[length]) != '\0') {
        if (!isalnum(c) && c != '_') {
            return 0;
        }
        length++;
    }

    // Check the length of the identifier
    if (length > MAX_ID_LENGTH) {
        return 0;
    }

    return 1;
}

int main() {
    char id[MAX_ID_LENGTH + 1];
    printf("Enter an identifier: ");
    scanf("%s", id);

    if (isValidIdentifier(id)) {
        printf("%s is a valid identifier\n", id);
    } else {
        printf("%s is not a valid identifier\n", id);
    }

    return 0;
}

