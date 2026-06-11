//816044402 
//DILLON GANPAT 




#include <iostream>
#include <cstdlib>
#include <fstream>
#include "NodeTypes.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "Data.h"
using namespace std;


BTNode * initBSTFromFile (char fileName[]) {
	
	BTNode * root = NULL;
	
	ifstream inputFile;
	City city;
	int numCities;
	
	inputFile.open(fileName);
	
	if (!inputFile.is_open()) {
		cout << "Input file " << fileName << " could not be opened. Aborting ..." << endl;
		return root;
	}

	numCities = 0;
	inputFile >> city.name;
		
	while (!inputFile.eof()) {
		inputFile >> city.latitude >> city.longitude;
		inputFile >> city.country >> city.country_iso2;
		inputFile >> city.population;
	
		numCities++;

		root = insertBST (root, city);

		inputFile >> city.name;
	}

	inputFile.close();
	
	//i added in this line to match sample output
	cout << "Root of BST created with " << root->data.name << "." << endl;  
	cout << endl; 
	
	cout << numCities << " cities read from " << fileName << " and stored in BST." << endl;
	
	return root;
}

BTNode* insertBST(BTNode* root, City data) {
    if (root == NULL) {
        BTNode* newNode = createBTNode(data);
        return newNode;
    }

    if (data.name < root->data.name) {
        root->left = insertBST(root->left, data);
    } 
    else {
        root->right = insertBST(root->right, data);
    }

    return root;
}


BTNode * containsBST (BTNode * root, string cityName) {
    if (root == NULL)
        return NULL;
    if (cityName == root->data.name)
        return root;
    if (cityName < root->data.name)
        return containsBST(root->left, cityName);
    else
        return containsBST(root->right, cityName);
}

BTNode * minimumBST (BTNode * root) {
    if (root == NULL)
        return NULL;
    
    if (root->left == NULL)
        return root;
    
    return minimumBST(root->left);
}

BTNode * maximumBST (BTNode * root) {
    if (root == NULL)
        return NULL;
    
    if (root->right == NULL)
        return root;
    
    return maximumBST(root->right);
}

BTNode * inOrderSuccessor (BTNode * node) {
    if (node == NULL)
        return NULL;
    
    if (node->right != NULL)
        return minimumBST(node->right);
    
    BTNode* parent = node->parent;
    while (parent != NULL && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    
    return parent;
}


void rangeBST(BTNode * root, string lowerName, string upperName) {
    if (root == NULL) {
        cout << "--> 0 keys were found in the range given." << endl;
        return;
    }
        
    int count = 0;
     BTNode* stack[2000];
    int top = -1;
    BTNode* current = root;
    
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        
        if (current->data.name >= lowerName && current->data.name <= upperName) {
            count++;
        }
        
        current = current->right;
    }
        if (count > 0) {
        top = -1;
        current = root;
        
        while (current != NULL || top >= 0) {
             while (current != NULL) {
                stack[++top] = current;
                current = current->left;
            }
            current = stack[top--];
            
            if (current->data.name >= lowerName && current->data.name <= upperName) {
                cout << current->data.name << " ";
            }
            current = current->right;
        }
        cout << endl;
    }
    
    cout << "--> " << count << " keys were found in the range given." << endl;
}



BTNode * deleteBST (BTNode * root, string key) {
    if (root == NULL)
        return NULL;
    
    if (key < root->data.name) {
        root->left = deleteBST(root->left, key);
    } else if (key > root->data.name) {
        root->right = deleteBST(root->right, key);
    } else {
        if (root->left == NULL) {
            BTNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            BTNode* temp = root->left;
            delete root;
            return temp;
        } else {
            BTNode* successor = minimumBST(root->right);
            root->data = successor->data;
            root->right = deleteBST(root->right, root->data.name);
        }
    }
    return root;
}






void statisticsBST (BTNode * root) {
    if (root == NULL) {
        cout << "BST is empty." << endl;
        return;
    }
    
    int treeHeight = height(root);
    int oneChildNodes = numOneChild(root);
    BTNode* minNode = minimumBST(root);
    BTNode* maxNode = maximumBST(root);
    
    int levels[2000] = {0};
    int numLevels = levelOrder(root, levels);
    
    cout << "--> Statistics on BST:" << endl << endl;
    cout << "Height of binary tree: " << treeHeight << endl;
    cout << "Number of non-terminal nodes with one child: " << oneChildNodes << endl;
    cout << "Smallest key: " << minNode->data.name << endl;
    cout << "Biggest key: " << maxNode->data.name << endl;
    cout << endl;
    cout << "Number of levels: " << numLevels << endl;
    cout << endl;
    cout << "Level Number    Nodes" << endl;
    cout << "============    ======" << endl;
    cout << endl;
    
    for (int i = 0; i < numLevels; i++) {
        cout << "    " << i << "    " << levels[i] << endl;
    }
}








BTNode * reBalanceBST (BTNode * root) {
    if (root == NULL)
        return NULL;
    
    int totalNodes = moment(root);
    BTNode** A = new BTNode*[totalNodes];
    int index = 0;
    
    BTNode* stack[2000];
    int top = -1;
    BTNode* current = root;
    
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        A[index++] = current;  
        current = current->right;
    }
    
    BTNode* newRoot = NULL;
    
    struct BalanceHelper {
        BTNode* operator()(BTNode* root, BTNode* A[], int first, int last) {
            if (first <= last) {
                int middle = (first + last) / 2;
                root = insertBST(root, A[middle]->data);
                root = (*this)(root, A, first, middle - 1);
                root = (*this)(root, A, middle + 1, last);
            }
            return root;
        }
    };
    
    BalanceHelper balanceHelper;
    newRoot = balanceHelper(newRoot, A, 0, totalNodes - 1);
    
    clearBT(root);
    delete[] A;
    
    cout << "Total nodes = " << totalNodes << endl;
    cout << "Root of BST created with " << newRoot->data.name << "." << endl;
    
    return newRoot;
}






