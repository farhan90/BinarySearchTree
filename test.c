#include <stdlib.h>
#include <stdio.h>
#include "bst.h"


void my_print_func(void *data){
	int *temp= (int*)data;
	printf("%d\n",*temp);
}

int main(){
	struct bst_node *root=NULL;
	int i;
	int list [5]={5,3,7,2,4};
	
	for(i=0;i<5;i++){
		int *ptr=&list[i];
		struct bst_node *node=create_node((void*)ptr,sizeof(int));
		if(node==NULL){
			printf("Error:cannot create the node\n");
			exit(1);
		}
		node->print_func=&my_print_func;
		printf("Added a function pointer\n");
		insert(&root,node,sizeof(int));
	}
	free_tree(&root);
	return 0;
}
