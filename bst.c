#include "bst.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void insert(struct bst_node **root, struct bst_node *node, int size){

	struct bst_node *prev=NULL;
	struct bst_node *curr=*root;
	
	/*The tree is empty*/
	if(curr==NULL){
		*root=node;
		return;
	}	

	while(curr){
		prev=curr;
		/*if less than the current node value*/
		if(memcmp(node->data,curr->data,size)<=0){
			curr=curr->left;
		}
		else{
			curr=curr->right;
		}
		
	}

	if(memcmp(node->data,prev->data,size)<=0){
		prev->left=node;
	}
	else{
		prev->right=node;
	}
}


struct bst_node *create_node(void *data, int size){
	struct bst_node *node = malloc(sizeof(struct bst_node));	
	if(node==NULL){
		printf("Cannot create a node\n");
		return NULL;
	}

	node->data=malloc(size);

	if(node->data==NULL){
		printf("Cannot allocate memory for node data\n");
		return NULL;
	}
	memcpy(node->data,data,size);
	node->left=NULL;
	node->right=NULL;
	return node;

}

void free_tree(struct bst_node **root){
	if((*root)->left!=NULL){
		free_tree(&(*root)->left);
	}

	if((*root)->right!=NULL){
		free_tree(&(*root)->right);
	}
	
		
	if((*root)->print_func){
		(*root)->print_func((*root)->data);
	}
	free((*root)->data);
	free(*root);
	

	 
}
