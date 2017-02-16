#include "doubleLinkedList.h"

_Node_Details_* reverseList(_Node_Details_ *nodeDetails){

	_Node_ *temp_Node = (_Node_*)malloc(sizeof(_Node_));
	_Node_ *temp_1_Node = (_Node_*)malloc(sizeof(_Node_));

	temp_Node = nodeDetails->headNode;

	/* Swap the previous and next pointers */

	while(NULL != temp_Node){

		temp_1_Node = temp_Node->prevNode;
		temp_Node->prevNode = temp_Node->nextNode;
		temp_Node->nextNode = temp_1_Node;

		temp_Node = temp_Node->prevNode; 
	}

	/* Swap the head and tail node adresses in the details structure */

	temp_Node = nodeDetails->headNode;
	nodeDetails->headNode = nodeDetails->tailNode;
	nodeDetails->tailNode = temp_Node;
	
	return nodeDetails;
}
