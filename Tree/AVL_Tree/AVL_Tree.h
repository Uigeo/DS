
#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__


#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024
#define WORD_LEN 128
#define MAX(a,b) ((a>b)?a:b)

typedef struct Node {
	struct Node *left;
	struct Node *right;
	char source[WORD_LEN];
	char target[WORD_LEN];
}AVL_node;


typedef struct Tree {
	AVL_node *root;
}AVL_tree;

/* Create a new AVL tree. */
AVL_tree* create_AVL_Tree();

/* Initialize a new node. */
AVL_node* create_node();

/*destroy a AVL tree */
void destroy_AVL_Tree(AVL_tree* tree);

/*deallocate each node */
void deallocate_node(AVL_node *node_p);

/* Find the height of an AVL node recursively */
int getHeight( AVL_node *node );

/* Find the balance of an AVL node */
int getBF( AVL_node *node );

/* Left Left Rotate */
AVL_node* LL_rotate( AVL_node *node_p );

/* Right Right Rotate */
AVL_node *RR_rotate( AVL_node *node_p );

/* Left Right Rotate */
AVL_node *LR_rotate( AVL_node *node_p ) ;

/* Right Left Rotate */
AVL_node *RL_rotate( AVL_node *node_p ) ;

/* Balance a given node */
AVL_node *rebalance_node( AVL_node *node );

/* Balance a given tree */
void rebalance_tree( AVL_tree* tree ) ;

AVL_node* insert_node(AVL_node* node, char* source, char* target);

/* Insert a new node. */
void insert_AVL( AVL_tree *tree, char* source, char* target );

/* Find the node containing a given value */
AVL_node *searchTree( AVL_tree *tree, char* source ) ;

/* display the element following Inorder */
void displayInorder(AVL_node* node) ;

#endif
