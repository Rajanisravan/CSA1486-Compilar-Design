#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 10
#define MAX_LEN 100

typedef struct {
    char non_terminal;
    char productions[MAX_PRODUCTIONS][MAX_LEN];
    int count;
} Grammar;

void eliminateLeftRecursion(Grammar* grammar, int* numGrammars) {
    for (int i = 0; i < *numGrammars; i++) {
        int hasLeftRecursion = 0;
        char newNonTerminal = grammar[i].non_terminal + ('A' - 'A') + 1;
        Grammar newGrammar = {newNonTerminal, {}, 0};

        for (int j = 0; j < grammar[i].count; j++) {
            if (grammar[i].productions[j][0] == grammar[i].non_terminal) {
                hasLeftRecursion = 1;
                sprintf(newGrammar.productions[newGrammar.count++], "%s%c", grammar[i].productions[j] + 1, newNonTerminal);
            }
        }

        if (hasLeftRecursion) {
            Grammar updatedGrammar = {grammar[i].non_terminal, {}, 0};

            for (int j = 0; j < grammar[i].count; j++) {
                if (grammar[i].productions[j][0] != grammar[i].non_terminal) {
                    sprintf(updatedGrammar.productions[updatedGrammar.count++], "%s%c", grammar[i].productions[j], newNonTerminal);
                }
            }

            sprintf(newGrammar.productions[newGrammar.count++], "e");

            grammar[i] = updatedGrammar;
            grammar[(*numGrammars)++] = newGrammar;
        }
    }
}

void printGrammar(const Grammar* grammar, int numGrammars) {
    for (int i = 0; i < numGrammars; i++) {
        printf("%c -> ", grammar[i].non_terminal);
        for (int j = 0; j < grammar[i].count; j++) {
            printf("%s", grammar[i].productions[j]);
            if (j < grammar[i].count - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }
}

int main() {
    Grammar grammar[MAX_PRODUCTIONS] = {
        {'S', {"Sa", "b"}, 2}
    };
    int numGrammars = 1;

    printf("Original Grammar:\n");
    printGrammar(grammar, numGrammars);

    eliminateLeftRecursion(grammar, &numGrammars);

    printf("\nGrammar after eliminating left recursion:\n");
    printGrammar(grammar, numGrammars);

    return 0;
}
