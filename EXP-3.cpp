#include <stdio.h>
#include <ctype.h>

void recognizeOperators(char c) {
    switch (c) {
        case '+':
            printf("Operator: +\n");
            break;
        case '-':
            printf("Operator: -\n");
            break;
        case '*':
            printf("Operator: *\n");
            break;
        case '/':
            printf("Operator: /\n");
            break;
        default:
            break;
    }
}

void lexicalAnalyzer(FILE *file) {
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            continue;
        } else if (isalpha(c) || c == '_') {
            // Skip over identifiers for this example
            while ((c = fgetc(file)) != EOF && (isalnum(c) || c == '_'));
            if (c != EOF) ungetc(c, file);
        } else if (isdigit(c)) {
            // Skip over constants for this example
            while ((c = fgetc(file)) != EOF && isdigit(c));
            if (c != EOF) ungetc(c, file);
        } else {
            recognizeOperators(c);
        }
    }
}

int main() {
    printf("Enter the code (end input with Ctrl+D):\n");

    lexicalAnalyzer(stdin);

    return 0;
}
