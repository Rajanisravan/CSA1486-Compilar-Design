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

void eliminateLeftFactoring(Grammar* grammar, int* numGrammars) {
    for (int i = 0; i < *numGrammars; i++) {
        int prefixLength = 0;
        char commonPrefix[MAX_LEN];
        commonPrefix[0] = '\0';
        for (int j = 0; j < grammar[i].count; j++) {
            for (int k = j + 1; k < grammar[i].count; k++) {
                int l = 0;
                while (grammar[i].productions[j][l] != '\0' && grammar[i].productions[k][l] != '\0' &&
                       grammar[i].productions[j][l] == grammar[i].productions[k][l]) {
                    l++;
                }
                if (l > prefixLength) {
                    prefixLength = l;
                    strncpy(commonPrefix, grammar[i].productions[j], prefixLength);
                    commonPrefix[prefixLength] = '\0';
                }
            }
        }

        if (prefixLength > 0) {
            char newNonTerminal = grammar[i].non_terminal + ('A' - 'A') + 1;
            Grammar newGrammar = {newNonTerminal, {}, 0};
            Grammar updatedGrammar = {grammar[i].non_terminal, {}, 0};

            for (int j = 0; j < grammar[i].count; j++) {
                if (strncmp(grammar[i].productions[j], commonPrefix, prefixLength) == 0) {
                    sprintf(newGrammar.productions[newGrammar.count++], "%s", grammar[i].productions[j] + prefixLength);
                } else {
                    sprintf(updatedGrammar.productions[updatedGrammar.count++], "%s", grammar[i].productions[j]);
                }
            }

            sprintf(updatedGrammar.productions[updatedGrammar.count++], "%s%c", commonPrefix, newNonTerminal);

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
        {'S', {"abc", "abd", "aef", "gh"}, 4}
    };
    int numGrammars = 1;

    printf("Original Grammar:\n");
    printGrammar(grammar, numGrammars);

    eliminateLeftFactoring(grammar, &numGrammars);

    printf("\nGrammar after eliminating left factoring:\n");
    printGrammar(grammar, numGrammars);

    return 0;
}

