/*
** EPITECH PROJECT, 2021
** Linked List
** File description:
** A generic linked list
*/

#include <stdlib.h>
#include <string.h>
#include "list.h"

void list_action(struct list *list,
int (*fun)(struct node *node, void *arg), void *arg)
{
    struct node *current_node = list->head;

    while (current_node) {
        if (fun(current_node, arg))
            break;
        current_node = current_node->next;
    }
}

int list_push(struct list *list, struct node node)
{
    struct node *new = malloc(sizeof(struct node));

    if (!new)
        return -1;
    memcpy(new, &node, sizeof(struct node));
    if (list->empty) {
        list->head = new;
        list->empty = false;
    } else {
        list_action(list, &node_push_back, (void *)new);
    }
    list->length++;
    return 1;
}

struct list *list_create(void)
{
    struct list new = {true, 0, NULL};
    struct list *allocate = malloc(sizeof(struct list));

    if (!allocate)
        return NULL;
    memcpy(allocate, &new, sizeof(struct list));
    return allocate;
}

void list_destroy(struct list *list)
{
    list_action(list, &node_destroy, NULL);
    free(list);
}
