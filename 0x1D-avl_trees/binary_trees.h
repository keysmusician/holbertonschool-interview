#ifndef BINARY_TREES_H
# define BINARY_TREES_H

#include <stddef.h>

#define TRUE 1
#define FALSE 0
#define FAIL -1

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
void binary_tree_print(const binary_tree_t *);
int binary_tree_is_avl(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
