#include <stdlib.h>
#include "leaftree.h"

ltn_t *
leaftree_init (void)
{
    ltn_t *tmp = malloc (sizeof (ltn_t));

    if (tmp)
    {
        tmp->l = 0;
    }

    return (tmp);
}

void
leaftree_rotate_left (ltn_t *n)
{
    ltn_t   *tmp_n = n->l;
    size_t   tmp_k = n->k;

    n->l    = n->r;
    n->k    = n->r->k;
    n->r    = n->l->r;
    n->l->r = n->l->l;
    n->l->l = tmp_n;
    n->l->k = tmp_k;
}

void
leaftree_rotate_right (ltn_t *n)
{
    ltn_t   *tmp_n = n->r;
    size_t   tmp_k = n->k;

    n->r    = n->l;
    n->k    = n->l->k;
    n->l    = n->r->l;
    n->r->l = n->r->r;
    n->r->r = tmp_n;
    n->r->k = tmp_k;
}

size_t *
leaftree_find (ltn_t *n, size_t k)
{
    size_t *rv = 0;

    if (!n->l)
    {
        goto end;
    }

    while (n->r)
    {
        if (k < n->k)
        {
            n = n->l;
        }
        else
        {
            n = n->r;
        }
    }

    if (k == n->k)
    {
        rv = &n->v;
    }

end:
    return (rv);
}
