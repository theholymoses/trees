#ifndef LEAFTREE_H
#define LEAFTREE_H

#include <stddef.h>

// if !root.l                   the tree is empty
// if  root.l && !root.r        root is a leaf, the tree contains only 1 object
// if  root.l &&  root.r        root.l and root.r are subtrees
// For each node l in a tree l.k < root.k and r.k >= root.k

struct leaftree_node_t
{
    size_t              k;      // key
    leaftree_node_t    *l;      // left
    leaftree_node_t    *r;      // right
    size_t              v;      // value
};
typedef struct leaftree_node_t ltn_t;

ltn_t *
leaftree_init (void);

void
leaftree_rotate_left (ltn_t *n);

void
leaftree_rotate_right (ltn_t *n);

size_t *
leaftree_find (ltn_t *n, size_t k);

#endif /* LEAFTREE_H */
