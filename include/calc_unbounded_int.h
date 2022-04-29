#ifndef PROJET_CALC_UNBOUNDED_INT_H
#define PROJET_CALC_UNBOUNDED_INT_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "unbounded_int.h"

typedef struct memory memory;

typedef struct interpreter interpreter;

extern interpreter *create_interpreter(FILE *input, FILE *output);

extern void destroy_interpreter(interpreter *interpreter);

/**
 * Interprets instructions from one file and writes the result to another file.
 * If the input file is NULL then stdin is used.
 * If the output file is NULL then stdout is used.
 *
 * @param input the file with the instructions to execute
 * @param output The file to which the result is redirected
 */
extern void interpret(interpreter *interpreter);

/**
 * Checks if the variable name is valid.
 * The equivalent in regex is `[a-zA-Z_][a-zA-Z_0-9]*`
 *
 * @param name the name of a variable
 * @return if the name is valid
 */
extern bool valid_variable_name(char *name);

/**
 * Checks if the variable is already defined.
 *
 * @param mem the memory where the variable is stored
 * @param name the name of the variable
 * @return
 */
extern bool is_assigned(memory *mem, char *name);

/**
 * Assign the value with the name of the variable.
 * If the name is already used or the variable name is not valid the operation will fail.
 *
 * @param mem the memory where the variable is stored
 * @param name the name of the variable
 * @param u the value to assign
 * @return if the operation fails return NULL else a pointer
 */
extern unbounded_int *assign(memory *mem, char *name, unbounded_int u);

/**
 * Get the value of a variable from its name.
 *
 * @param mem the memory where the variable is stored
 * @param name the name of a variable
 * @return if the variable exists return its value else NULL
 */
extern unbounded_int *value_of(memory *mem, char *name);

/**
 * Evaluates a string and returns the result of the operations.
 *
 * @param line the operation to be evaluated
 * @return the result of the operation
 */
extern unbounded_int eval(char *line);

/**
 * Print the value of a variable.
 *
 * @param interpreter the interpreter
 * @param name the name of a variable
 */
extern void print(interpreter *interpreter, char *name);

#endif //PROJET_CALC_UNBOUNDED_INT_H
