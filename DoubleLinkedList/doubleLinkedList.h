#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define  MAX_NODE 5

#define _LIST_OK_    0
#define _EMPTY_LIST_ 1
#define _FULL_LIST_  2

struct _Node_ {
	int value;
	struct _Node_ *nextNode;
	struct _Node_ *prevNode;
};

struct _Node_Details_ {
	uint8_t numberOfNodes;
	struct _Node_ *headNode;
	struct _Node_ *tailNode;
	uint8_t listStatus;
};

typedef struct _Node_ _Node_;
typedef struct _Node_Details_  _Node_Details_;


_Node_* createNewNode(int value);
_Node_Details_* createLinkedList(_Node_ *startNode, _Node_Details_ *nodeDetails);
_Node_Details_* addToHead(_Node_Details_ *nodeDetails, _Node_ *newNode);
_Node_Details_* addToTail(_Node_Details_ *nodeDetails, _Node_ *newNode);
_Node_Details_* deleteNode(_Node_Details_ *nodeDetails, int value);

void displayList(_Node_Details_ *nodeDetails);

#endif