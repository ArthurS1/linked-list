/*
** EPITECH PROJECT, 2021
** Linked list
** File description:
** modifiers
*/

#include <stdlib.h>
#include <string.h>
#include "list.h"

int node_push_back(struct node *node, void *args)
{
    struct node *new = (struct node *)args;

    if (!node->next) {
        new->next = NULL;
        node->next = new;
        return true;
    }
    return false;
}

int node_destroy(struct node *node, void *args)
{
    static struct node *last = NULL;
    struct node *current = (struct node *)node;
    (void)args;

    if (current->next == NULL) {
        if (last)
            free(last);
        free(current);
        return true;
    } else if (last) {
        free(last);
        last = current;
    } else if (!last)
        last = current;
    return false;
}
