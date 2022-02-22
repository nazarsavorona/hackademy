#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <../include/binary_tree.h>

node_t  *allocnode()
{
    return (node_t *) malloc(sizeof(node_t));
}

node_t  *initnode(char *key, void *data)
{
    node_t *new_node = allocnode();
    new_node->key = key;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

node_t  *insert(node_t *root, char *key, void *data)
{
    if (!root)
    {
        return root = initnode(key, data);
    }

    node_t **target = &(root->left);

    if (strcmp(root->key, key) <= 0)
    {
        target = &(root->right);
    }
        
    if (!(*target))
    {
        return *target = initnode(key, data); 
    }

    *target = insert(*target, key, data);

    return NULL;
}

void print_node(node_t *node)
{
    if (node)
    {
        printf("Node: {key: %s, data: %p, left: %p, right: %p}\n",
               node->key, node->data, node->left, node->right);
    }
    else 
    {
        printf("NULL node\n");
    }
}

void visit_tree(node_t *node, void (*fp)(node_t *root))
{
    if (!node)
    {
        return;
    }

    fp(node);
    visit_tree(node->left, fp);
    visit_tree(node->right, fp);
}

void destroy_tree(node_t *node, void (*fdestroy)(node_t *root))
{
    if (!node)
    {
        return;
    }

    destroy_tree(node->left, fdestroy);
    destroy_tree(node->right, fdestroy);
    fdestroy(node);
    free(node);
}
