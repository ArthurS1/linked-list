/*
** EPITECH PROJECT, 2021
** Linked list
** File description:
** list.h
*/

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

struct node {
    void *content;
    struct node *next;
};

struct list {
    bool empty;
    int length;
    struct node *head;
};

// allocates and appends a node to the list
int list_push(struct list *list, struct node node);

// allocates a new list
struct list *list_create(void);

// frees a list and its nodes
void list_destroy(struct list *list);

// executes a function on all elements of the list
void list_action(struct list *list, \
int (*fun)(struct node *node, void *arg), void *arg);

// default actions needed by builtin functions
int node_push_back(struct node *node, void *args);
int node_destroy(struct node *node, void *args);
#endif /* !LIST_H_ */
