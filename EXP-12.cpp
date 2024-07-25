#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char result[10];
    char arg1[10];
    char op[2];
    char arg2[10];
} TAC;

TAC tac[MAX]; // Array to store three-address code
int tac_index = 0; // Index for the tac array
int temp_count = 0; // Counter for temporary variables

// Stack structure for Shunting Yard algorithm
typedef struct {
    char items[MAX][10];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push item to stack
void push(Stack *s, char *item) {
    if (s->top < MAX - 1) {
        strcpy(s->items[++(s->top)], item);
    }
}

// Pop item from stack
void pop(Stack *s, char *item) {
    if (!isEmpty(s)) {
        strcpy(item, s->items[(s->top)--]);
    }
}

// Peek item from stack
void peek(Stack *s, char *item) {
    if (!isEmpty(s)) {
        strcpy(item, s->items[s->top]);
    }
}

// Check precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Convert infix expression to postfix expression
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int i = 0, k = 0;
    char ch;
    char temp[10];

    while ((ch = infix[i++]) != '\0') {
        if (isspace(ch)) {
            continue;
        }

        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            temp[0] = ch;
            temp[1] = '\0';
            push(&stack, temp);
        } else if (ch == ')') {
            while (!isEmpty(&stack) && strcmp(stack.items[stack.top], "(") != 0) {
                pop(&stack, temp);
                postfix[k++] = temp[0];
            }
            pop(&stack, temp); // Remove '(' from stack
        } else if (strchr("+-*/", ch)) {
            temp[0] = ch;
            temp[1] = '\0';
            while (!isEmpty(&stack) && precedence(stack.items[stack.top][0]) >= precedence(ch)) {
                pop(&stack, temp);
                postfix[k++] = temp[0];
            }
            push(&stack, temp);
        }
    }

    while (!isEmpty(&stack)) {
        pop(&stack, temp);
        postfix[k++] = temp[0];
    }
    postfix[k] = '\0';
}

// Generate three-address code from postfix expression
void generateTAC(char *postfix) {
    Stack stack;
    initStack(&stack);
    int i = 0;
    char ch;
    char op1[10], op2[10], result[10];
    char temp[10];

    while ((ch = postfix[i++]) != '\0') {
        if (isalnum(ch)) {
            temp[0] = ch;
            temp[1] = '\0';
            push(&stack, temp);
        } else if (strchr("+-*/", ch)) {
            pop(&stack, op2); // Pop operand 2
            pop(&stack, op1); // Pop operand 1

            sprintf(result, "t%d", temp_count++); // Create temporary variable
            strcpy(tac[tac_index].result, result);
            strcpy(tac[tac_index].arg1, op1);
            sprintf(tac[tac_index].op, "%c", ch);
            strcpy(tac[tac_index].arg2, op2);
            tac_index++;

            push(&stack, result); // Push result to stack
        }
    }
}

int main() {
    char expression[MAX];
    char postfix[MAX];

    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character from input if present
    size_t len = strlen(expression);
    if (len > 0 && expression[len-1] == '\n') {
        expression[len-1] = '\0';
    }

    infixToPostfix(expression, postfix);
    generateTAC(postfix);

    printf("Three-address code for the given expression:\n");
    for (int i = 0; i < tac_index; i++) {
        printf("%s = %s %s %s\n", tac[i].result, tac[i].arg1, tac[i].op, tac[i].arg2);
    }

    return 0;
}
