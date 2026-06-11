//816044402 
//DILLON GANPAT 


#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"
#include "Queue.h"
#include "Data.h"

using namespace std;



BTNode * createBTNode (City data) {
	BTNode * newNode; 
   
	newNode = new BTNode;
   
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
   
	return newNode;
}



void preOrder (BTNode * root) {
	
	if (root == NULL)
		return;
		
	cout << root->data.name << " ";

	preOrder (root->left);
	preOrder (root->right);
}



void inOrder (BTNode * root) {
	
	if (root == NULL)
		return;

	inOrder (root->left);
	
	cout << root->data.name << " ";
	
	inOrder (root->right);
}



void postOrder (BTNode * root) {
	
	if (root == NULL)
		return;

	postOrder (root->left);
	postOrder (root->right);
	
	cout << root->data.name << " ";
}



int moment (BTNode * root) {

	if (root == NULL)
		return 0;
		
	return (1 + moment (root->left) + moment (root->right));
}



int numOneChild(BTNode * root) {
    if (root == NULL) return 0;

    int count = 0;

    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL)) {
        count = 1;
    }

    return count + numOneChild(root->left) + numOneChild(root->right);
}

int numTerminal (BTNode * root) {

	if (root == NULL)
		return 0;
		
	if (root->left == NULL && root->right == NULL)
		return 1;
		
	return (numTerminal (root->left) + numTerminal (root->right));
}



int nodeDepth (BTNode * node) {
	int branch;
	
	branch = 0;
	
	if (node == NULL)
		return -1;
		
	while (node->parent != NULL) {
		node = node->parent;
		branch++;
	}
	
	return branch;
}






/////////////////////////////////////////////////////////////////////////////////////////////////


int height (BTNode * root) {

  if (root == NULL)
        return -1;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return 1 + max(leftHeight, rightHeight);
}



int levelOrder (BTNode * root, int levels[]) {
 if (root == NULL)
        return 0;
    
    for (int i = 0; i < 100; i++) levels[i] = 0;
    
    Queue* q = initQueue();
    enqueue(q, root);
    
    int levelNum = 0;
    
    while (!isEmptyQueue(q)) {
        int numNodes = sizeQueue(q);
        levels[levelNum] = numNodes;
        
        for (int i = 0; i < numNodes; i++) {
            BTNode* current = dequeue(q);
            if (current->left != NULL) enqueue(q, current->left);
            if (current->right != NULL) enqueue(q, current->right);
        }
        levelNum++;
    }
    
    while (!isEmptyQueue(q)) dequeue(q);
    delete q;
    
    return levelNum;
}

void clearBT (BTNode * root) {
    if (root == NULL)
        return;
    
    clearBT(root->left);
    clearBT(root->right);
    delete root;
}
























