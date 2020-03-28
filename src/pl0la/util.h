#ifndef PL0LA_UTIL_H
#define PL0LA_UTIL_H

/**
 * @file util.h
 * @author Keenan Turley (keenan.turley@knights.ucf.edu)
 * @brief Utitity functions for printing lexical analyzer data
 *
 */

#include "../common/token_list.h"

/**
 * @brief Prints a file to stdout
 *
 * Prints the entire contents of a file to stdout, line by line.
 *
 * @param file_path A string representing the path to the file to print
 */
void print_file(char *file_path);

/**
 * @brief Prints the lexeme table
 *
 * Prints a table row by row of lexeme names and token types
 * Every token in the given list is printed.
 *
 * @param l A pointer to the list of tokens to print
 */
void print_lexeme_table(token_list_t *l);

/**
 * @brief Prints a list of lexeme types and names
 *
 * Prints a space delimited list of lexeme types in decimal representation.
 * If an identifier type is encountered, its type with be followed by its name.
 *
 * @param l A pointer to the list of tokens to print
 */
void print_lexeme_list(token_list_t *l);

void print_lexeme_list_symbolic(token_list_t *l);

#endif /* PL0LA_UTIL_H */
