#ifndef BST_H
#define BST_H



struct bst_node{
	void *data;
	struct bst_node *left;
	struct bst_node *right;
	void (*print_func)(void *data);
};

void insert(struct bst_node **root,struct bst_node *node, int size);
struct bst_node *create_node(void *data, int size);
void free_tree(struct bst_node **root); 

#endif
