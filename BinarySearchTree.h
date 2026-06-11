#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

#include "Data.h"
using namespace std;

BTNode * initBSTFromFile (char fileName[]);
BTNode * insertBST (BTNode * root, City data);
BTNode * containsBST (BTNode * root, string cityName);

BTNode * minimumBST (BTNode * root);
BTNode * maximumBST (BTNode * root);
BTNode * inOrderSuccessor (BTNode * btNode);

void rangeBST (BTNode * root, string lowerName, string upperName);
BTNode * deleteBST (BTNode * root, string cityName);
void statisticsBST (BTNode * root);

BTNode * reBalanceBST (BTNode * root);

#endif
