#include "symbol.h"

#include <string.h>

void init_symbol_table(symbol_table_t *table) {
    table->num_symbols = 0;
    table->var_address_index = 4;
}

symbol create_symbol(kind_type kind, char name[12], int value, int level,
    int address, mark_type mark) {
    symbol s;
    s.kind = kind;
    memcpy(s.name, name, sizeof(char) * 12);
    s.value = value;
    s.level = level;
    s.address = address;
    s.mark = mark;
    return s;
}

symbol create_const_symbol(char name[12], int value) {
    symbol s;
    s.kind = KIND_CONST;
    memcpy(s.name, name, sizeof(char) * 12);
    s.value = value;
    s.level = 0;
    s.address = 0;
    s.mark = MARK_VALID;

    return s;
}

symbol create_var_symbol(char name[12], int level) {
    symbol s;
    s.kind = KIND_VAR;
    memcpy(s.name, name, sizeof(char) * 12);
    s.value = 0;
    s.level = 0;
    s.address = 0;
    s.mark = MARK_VALID;
    
    return s;
}

symbol create_proc_symbol(char name[12], int level) {
    symbol s;
    s.kind = KIND_PROC;
    memcpy(s.name, name, sizeof(char) * 12);
    s.value = 0;
    s.level = level;
    s.address = 0;
    s.mark = MARK_VALID;
    
    return s;
}

void insert_symbol(symbol_table_t *table, symbol *sym) {
    // Grab the address of the destination symbol from the table
    symbol *s = &(table->symbols[table->num_symbols]);

    if (sym->kind == KIND_VAR)
        sym->address = (table->var_address_index)++;

    // Copy the contents of the passed in symbol to the destination
    memcpy(s, sym, sizeof(symbol));

    (table->num_symbols)++;
}

symbol *search_symbol(symbol_table_t *table, char name[12]) {
    // Search from back to front for symbol name
    for (int i = table->num_symbols - 1; i >= 0; i--) {
        symbol *s = &(table->symbols[i]);

        // Symbol must be valid and have the same name
        if (s->mark == MARK_VALID && strcmp(name, s->name) == 0) {
            return &(table->symbols[i]);
        }
    }

    // Symbol was not found, return NULL
    return NULL;
}

void invalidate_symbols(symbol_table_t *table, int level) {
    for (int i = table->num_symbols - 1; i >= 0; --i) {
        if (table->symbols[i].level >= level) {
            table->symbols[i].mark = MARK_INVALID;
        }
    }
}
