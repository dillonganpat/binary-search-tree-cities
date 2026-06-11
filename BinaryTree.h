#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include "NodeTypes.h"

BTNode * createBTNode (City data);
void preOrder (BTNode * root);
void inOrder (BTNode * root);
void postOrder (BTNode * root);

int moment (BTNode * root);
bool contains (BTNode * root, string cityName);
City maximum (BTNode * root);
int numOneChild (BTNode * root);
int numTerminal (BTNode * root);

int nodeDepth (BTNode * node);

int height (BTNode * root);
int levelOrder (BTNode * root, int levels[]);
void clearBT (BTNode * root);

#endif
