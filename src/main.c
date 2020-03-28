#include "common/token_list.h"
#include "common/token.h"

#include "pl0la/scanner.h"
#include "pl0la/util.h"

#include "pl0pcg/parser.h"



#include "pm0vm/pm0.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_usage();
void print_assembly(code_generator_t *cg);
void import_code(p_machine *vm, code_generator_t *cg);

int main(int argc, char *argv[])
{
    // Flags
    bool print_lexemes = false;
    bool print_code = false;
    bool vm_debug_output = false;

    // Handle arguments
    if (argc < 2 || argc > 5) {
        print_usage();
        exit(EXIT_FAILURE);
    } else if (argc == 5) {
        print_lexemes = print_code = vm_debug_output = true;
    } else {
        // Check each argument between first and last
        for (int i = 1; i < argc - 1; i++) {
            if (strlen(argv[i]) != 2) {
                print_usage();
                exit(EXIT_FAILURE);
            }
            switch (argv[i][1]) {
                case 'l':
                    print_lexemes = true;
                    break;
                case 'a':
                    print_code = true;
                    break;
                case 'v':
                    vm_debug_output = true;
                    break;
                default:
                    print_usage();
                    exit(EXIT_FAILURE);
                    break;
            }
        }
    }

    char *file_path = argv[argc - 1];
    
    // ---- Lexical Analyzer ----
    token_list_t * tl = tokenize(file_path);

    if (print_lexemes) {
        // Print out lexeme list
        printf("Lexeme List:\n");
        print_lexeme_list(tl);
        printf("\n");

        printf("Lexeme List (Symbolic Representation):\n");
        print_lexeme_list_symbolic(tl);
    }

    // ---- Parser + Code Generator ----
    // Create parser
    parser_t parser;
    
    // Casting token list (DANGEROUS PROBABLY SHOULD BE AVOIDED)
    // Possible fix: create a common token_list structure
    init_parser(&parser, tl);

    // Parse the program
    parse_program(&parser);

    printf("No errors, program is syntactically correct\n");

    if (print_code) 
        print_assembly(&(parser.code_generator));

    // Free the token list
    tl = free_token_list(tl);

    // ---- Virtual Machine ----
    p_machine *vm = create_machine();

    if (vm_debug_output)
        vm->debug_mode = 1;

    // Import the codegen code into the vm
    import_code(vm, &(parser.code_generator));

    // Run the machine until halt
    run(vm);

    // Destroy the machine after we're done with it
    vm = destroy(vm);
    
    return EXIT_SUCCESS;
}

void print_usage() {
    fprintf(stderr, "usage: ./compile [-l -a -v] (file-path)\n");
    fprintf(stderr, "    -l : Print lexeme list\n");
    fprintf(stderr, "    -a : Print generated assembly code\n");
    fprintf(stderr, "    -v : Print virtual machine execution\n");
}

void print_assembly(code_generator_t *cg) {
    printf("Assembly Code:\n");
    for (int i = 0; i < cg->code_size; i++) {
        cg_instruction *inst = &(cg->code[i]);
        printf("%d %d %d %d\n", inst->op, inst->regiser_num, inst->lex_level, 
            inst->modifier);
    }
    printf("\n");
}

void import_code(p_machine *vm, code_generator_t *cg) {
    for (int i = 0; i < cg->code_size; i++) {
        vm->code[i].line_number = i;
        vm->code[i].op = cg->code[i].op;
        vm->code[i].r = cg->code[i].regiser_num;
        vm->code[i].l = cg->code[i].lex_level;
        vm->code[i].m = cg->code[i].modifier;
    }
    vm->code_length = cg->code_size;
}
