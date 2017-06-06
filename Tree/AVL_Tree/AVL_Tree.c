
#include "AVL_Tree.h"

/* Create a new AVL tree. */
AVL_tree* create_AVL_Tree() {
	AVL_tree *tree = NULL;

	if( ( tree = malloc( sizeof( AVL_tree ) ) ) == NULL ) {
		printf("Fail to allocate a memory of tree");
    exit(-1);
	}

	tree->root = NULL;

	return tree;
}

/* Initialize a new node. */
AVL_node *create_node() {
	AVL_node *new_node = NULL;

	if( ( new_node = malloc( sizeof( AVL_node ) ) ) == NULL ) {
    printf("Fail to allocate a memory of node");
    exit(-1);
	}

	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

/*destroy a AVL tree */
void destroy_AVL_Tree(AVL_tree* tree){
	deallocate_node(tree->root);
}

/*deallocate each node */
void deallocate_node(AVL_node *node_p){
	if(node_p->left) deallocate_node(node_p->left);
	if(node_p->right) deallocate_node(node_p->right);
	free(node_p);
}

/* return the height of an AVL node */
int getHeight( AVL_node *node ) {
  int height = 0;
	if (node != NULL) height = MAX(getHeight(node->left), getHeight(node->right)) + 1;
	return height;
}

/* return the balance of an AVL node */
int getBF( AVL_node *node ) {
	if(node == NULL) return 0;
	return getHeight(node->left)-getHeight(node->right) ;
}

/* Left Left Rotate */
AVL_node* LL_rotate( AVL_node *node_p ) {
  AVL_node* node_c = node_p->left;
	node_p->left = node_c->right;
	node_c->right = node_p;
	return node_c;
}

/* Right Right Rotate */
AVL_node *RR_rotate( AVL_node *node_p ) {
	AVL_node* node_c = node_p->right;
  node_p->right = node_c->left;
  node_c->left = node_p;
  return node_c;
}

/* Left Right Rotate */
AVL_node *LR_rotate( AVL_node *node_p ) {
	AVL_node* node_c = node_p->left;
  node_p->left = RR_rotate(node_c);
  return LL_rotate(node_p);
}

/* Right Left Rotate */
AVL_node *RL_rotate( AVL_node *node_p ) {
  AVL_node* node_c = node_p->right;
  node_p->right = LL_rotate(node_c);
  return RR_rotate(node_p);
}


/* Balance a given node */
AVL_node *rebalance_node( AVL_node *node ) {
	AVL_node *newroot = NULL;

	/* Balance our children, if they exist. */
	if( node->left )
		node->left  = rebalance_node( node->left  );
	if( node->right )
		node->right = rebalance_node( node->right );

	int bf = getBF( node );

	if( bf > 1 ) {
		if( getBF( node->left ) < 0 )	newroot = LR_rotate( node );
		else newroot = LL_rotate( node );
	}
	else if( bf < -1 ) {
		if( getBF( node->right ) > 0 )	newroot = RL_rotate( node );
		else newroot = RR_rotate( node );
	}
	else {
		newroot = node;
	}
	return newroot ;
}

/* Balance a given tree */
void rebalance_tree( AVL_tree* tree ) {

	AVL_node *newroot = NULL;

	newroot = rebalance_node( tree->root );

	if( newroot != tree->root )  {
		tree->root = newroot;
	}

}

/* Insert a new node. */
AVL_node* insert_node(AVL_node* node, char* source, char* target){
  if (node == NULL) {
		node = create_node();
		strcpy(node->source, source);
    strcpy(node->target, target);
	}
	else if (strcmp(node->source, source)>0) {
		node->left = insert_node(node->left, source, target);
	}
	else if (strcmp(node->source, source)<0) {
		(node)->right = insert_node(node->right ,source, target);
	}
	else {
		printf("\n This key is already exsisted. \n");
		exit(1);
	}

  return node;
}

/* Insert a new node in to AVL tree. */
void insert_AVL( AVL_tree *tree, char* source, char* target ) {
  tree->root = insert_node(tree->root, source, target);

  rebalance_tree(tree);

}

/* return the address of the node containing a given value */
AVL_node *searchTree( AVL_tree *tree, char* source) {
	AVL_node *current = tree->root;

	while( current && strcmp(source, current->source) != 0 ) {
		if( strcmp(source, current->source) > 0 )
			current = current->right;
		else
			current = current->left;
	}
	return current;
}

/* display all elements forrowing inorder*/
void displayInorder(AVL_node* node) {
	if (node) {
		displayInorder(node->left);
		printf("%s : %s", node->source, node->target);
		displayInorder(node->right);
	}
}
