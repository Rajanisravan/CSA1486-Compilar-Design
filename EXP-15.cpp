#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void infixToPostfix(const char *infix, char *postfix) {
    char stack[100];
    int top = -1;
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        if (isdigit(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; // pop '('
        } else {
            while (top != -1 && (stack[top] == '*' || stack[top] == '/' || 
                                 (stack[top] == '+' || stack[top] == '-') && (infix[i] == '+' || infix[i] == '-'))) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while (top != -1) {
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';
}
void generateCode(const char *postfix) {
    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            printf("PUSH %c\n", postfix[i]);
        } else {
            switch (postfix[i]) {
                case '+': printf("ADD\n"); break;
                case '-': printf("SUB\n"); break;
                case '*': printf("MUL\n"); break;
                case '/': printf("DIV\n"); break;
            }
        }
    }
}
int main() {
    char infix[100], postfix[100];
    printf("Enter an arithmetic expression (e.g., 3+(4*5)-7):\n");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0;
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Generated Code:\n");
    generateCode(postfix);
    return 0;
}
