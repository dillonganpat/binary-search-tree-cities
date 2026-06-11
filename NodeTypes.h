#ifndef _NODETYPES_H
#define _NODETYPES_H

#include <iostream>
#include "Data.h"
using namespace std;

struct BTNode {
	City data;
	BTNode * left;
	BTNode * right;
	BTNode * parent;
};

struct QueueNode {
	BTNode * data;
	QueueNode * next;
};

#endif
