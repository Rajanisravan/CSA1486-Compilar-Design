#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("PEMDAS: Parentheses, Exponentiation, Multiplication, Division, Addition, Subtraction\n");
    printf("Enter an expression: ");
    char expression[100];
    fgets(expression, sizeof(expression), stdin);
    // Remove newline character
    expression[strcspn(expression, "\n")] = '\0';

    printf("Order of evaluation:\n");
    printf("1. Parentheses: None\n");
    printf("2. Exponentiation: None\n");

    // Evaluate multiplication and division
    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] == '*') {
            int num1 = atoi(&expression[i-1]);
            int num2 = atoi(&expression[i+1]);
            int result = num1 * num2;
            printf("3. Multiplication and Division: %d*%d = %d\n", num1, num2, result);
            break;
        } else if (expression[i] == '/') {
            int num1 = atoi(&expression[i-1]);
            int num2 = atoi(&expression[i+1]);
            int result = num1 / num2;
            printf("3. Multiplication and Division: %d/%d = %d\n", num1, num2, result);
            break;
        }
        i++;
    }

    // Evaluate addition and subtraction
    int result = 0;
    i = 0;
    while (expression[i] != '\0') {
        if (expression[i] == '+') {
            int num = atoi(&expression[i+1]);
            result += num;
        } else if (expression[i] == '-') {
            int num = atoi(&expression[i+1]);
            result -= num;
        }
        i++;
    }
    printf("4. Addition and Subtraction: %s = %d\n", expression, result);

    printf("Final result: %d\n", result);

    return 0;
}

