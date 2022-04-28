#ifndef PROJET_ARITHMETIC_H
#define PROJET_ARITHMETIC_H

#include "unbounded_int.h"

typedef enum operator { ADD, SUB, MUL, NONE } operator;

/**
 * Represents an operator with two children or a number without children.
 */
typedef struct node node;

/**
 * Represents a arithmetic expression in the form of a tree.
 * Each node is either an operator with two children or a number.
 */
typedef struct tree tree;

/**
 * Create a new node with an operator and two children.
 * @param op an operator (ADD, SUB, MUL)
 * @param left another node
 * @param right another node
 * @return a new node or NULL if it failed
 */
node *operator_to_node(operator op, node *left, node *right);

/**
 * Create a new node with a value.
 * @param value an number
 * @return a new node or NULL if it failed
 */
node *value_to_node(unbounded_int value);

/**
 * Create a new tree from a string.
 *
 * @param str a string representing an arithmetic expression
 * @return a new tree or NULL if it failed
 */
tree *string_to_tree(char *str);

/**
 * Transform a tree into an arithmetic expression.
 *
 * @param t a tree
 * @return a string
 */
char *tree_to_string(tree *t);

/**
 * Evaluate all the nodes of a tree until it remains only one with a value.
 *
 * @param t a tree
 */
void evaluate(tree *t);

/**
 * Free a node and its children recursively.
 *
 * @param n a node
 */
void free_node(node *n);

/**
 * Free a tree and all its nodes recursively.
 *
 * @param t a tree
 */
void free_tree(tree *t);

#endif //PROJET_ARITHMETIC_H
