#include <stdlib.h>
#include <stdio.h>

#include <../include/linked_list.h>

node_t  *list_create(void *data) 
{
    node_t *node = (node_t *) malloc(sizeof(node_t));

    node->data = data;
    node->next = NULL;

    return node;
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
    node_t *current = *head;
    node_t *next = NULL;

    while (current)
    {
        next = current->next;

        fp(current->data);
        free(current);        

        current = next;
    }
}

void list_push(node_t *head, void *data)
{
    node_t *current = head;

    while (current->next) 
    {
        current = current->next;
    }

    current->next = list_create(data);
}

void list_unshift(node_t **head, void *data)
{
    node_t *new_first = list_create(data);
    
    new_first->next = (*head)->next;
    
    (*head)->next = new_first;
}

void *list_pop(node_t **head)
{
    node_t *current = *head;
    node_t *tail;
    node_t *before_tail;

    while (current->next->next) 
    {
        current = current->next;
    }

    tail = current->next;
    before_tail = current;

    void *data = tail->data;

    free(tail);
    before_tail->next = NULL;

    return data;
}

void *list_shift(node_t **head)
{
    node_t *to_delete = *head;
    void *data = to_delete->data;

    *head = to_delete->next;
    free(to_delete);

    return data;
}

void *list_remove(node_t **head, int pos)
{
    node_t *current = *head;
    node_t *previous = current; 
    
    while (current->next && pos--)
    {
        previous = current;    
        current = current->next;
    }

    previous->next = current->next;
    void *data = current->data;

    free(current);

    return data;
}

void list_print(node_t *head)
{
    printf("List content:\n");

    while (head)
    {
        printf("%s", (char *)head->data);

        head = head->next;
    }
    printf("\n");
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
    while (head)
    {
        fp(head->data);

        head = head->next;
    }
}