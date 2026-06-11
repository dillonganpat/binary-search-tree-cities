#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include "NodeTypes.h"
	using namespace std;

struct Queue {
	QueueNode * top;
	QueueNode * last;
};

Queue * initQueue ();
bool isEmptyQueue (Queue * queue);
int sizeQueue (Queue * queue);
void enqueue (Queue * queue, BTNode * data);
BTNode * dequeue (Queue * queue);

#endif
