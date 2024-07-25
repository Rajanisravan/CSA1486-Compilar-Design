#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SYMBOLS 100
#define MAX_NAME_LENGTH 50
// Define a structure for the symbol table entries
typedef struct {
    char name[MAX_NAME_LENGTH];
    int address;
} Symbol;

typedef struct {
    Symbol symbols[MAX_SYMBOLS];
    int size;
} SymbolTable;

// Initialize the symbol table
void initializeSymbolTable(SymbolTable *table) {
    table->size = 0;
}

// Insert a symbol into the symbol table
void insertSymbol(SymbolTable *table, const char *name, int address) {
    if (table->size >= MAX_SYMBOLS) {
        printf("Symbol table is full.\n");
        return;
    }
    strcpy(table->symbols[table->size].name, name);
    table->symbols[table->size].address = address;
    table->size++;
}

// Search for a symbol in the symbol table
int searchSymbol(SymbolTable *table, const char *name) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->symbols[i].name, name) == 0) {
            return table->symbols[i].address;
        }
    }
    return -1;  // Symbol not found
}

// Display the symbol table
void displaySymbolTable(SymbolTable *table) {
    printf("Symbol Table:\n");
    printf("Name\tAddress\n");
    for (int i = 0; i < table->size; i++) {
        printf("%s\t%d\n", table->symbols[i].name, table->symbols[i].address);
    }
}

int main() {
    SymbolTable table;
    initializeSymbolTable(&table);

    insertSymbol(&table, "x", 1001);
    insertSymbol(&table, "y", 1002);
    insertSymbol(&table, "z", 1003);

    displaySymbolTable(&table);

    const char *searchName = "y";
    int address = searchSymbol(&table, searchName);
    if (address != -1) {
        printf("Symbol '%s' found at address %d\n", searchName, address);
    } else {
        printf("Symbol '%s' not found\n", searchName);
    }

    return 0;
}
