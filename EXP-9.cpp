#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
bool checkGrammar(const char *str) {
    int length = strlen(str);
    // Check if the string is empty
    if (length == 0) {
        return false;
    }
    // Rule 1: A sentence starts with a capital letter
    if (!isupper(str[0])) {
        return false;
    }
    // Rule 2: A sentence ends with a period
    if (str[length - 1] != '.') {
        return false;
    }
    // Rule 3: A sentence contains only alphabetic characters and spaces
    for (int i = 1; i < length - 1; i++) {
        if (!isalpha(str[i]) && str[i] != ' ') {
            return false;
        }
    }
    return true;
}
int main() {
    char input[100];
    printf("Enter a sentence: ");
    // Read the input sentence
    fgets(input, sizeof(input), stdin);
    // Remove the newline character if present
    input[strcspn(input, "\n")] = '\0';
    if (checkGrammar(input)) {
        printf("The sentence satisfies the grammar rules.\n");
    } else {
        printf("The sentence does not satisfy the grammar rules.\n");
    }
    return 0;
}
