#include <iostream>

#include "NodeTypes.h"
#include "Queue.h"

using namespace std;


Queue * initQueue () {
	Queue * queue = new Queue;
	queue->top = NULL;
	queue->last = NULL;
	return queue;
}


bool isEmptyQueue (Queue * queue) {
	if (queue->top == NULL)
		return true;
	else
		return false;		
}


int sizeQueue (Queue * queue) {

	QueueNode * curr;
	int size;

	curr = queue->top;	
	size = 0;
	
	while (curr != NULL) {
		curr = curr->next;
		size = size + 1;
	}
	
	return size;
}


void enqueue (Queue * queue, BTNode * data) {
	QueueNode * newNode = new QueueNode;
	newNode->data = data;
	newNode->next = NULL;
	
	if (isEmptyQueue(queue)) {
		queue->top = newNode;
		queue->last = newNode;
	}
	else {
		queue->last->next = newNode;
		queue->last = newNode;
	}
}


BTNode * dequeue (Queue * queue) {
	if (isEmptyQueue(queue))
		return NULL; 				// to indicate error if dequeuing from an empty queue
	
	QueueNode * toRemove;
	BTNode * data;
	
	toRemove = queue->top;
	data = toRemove->data;
	queue->top = toRemove->next;
	if (queue->top == NULL)
		queue->last = NULL;
		
	delete (toRemove);
	
	return data;
}
