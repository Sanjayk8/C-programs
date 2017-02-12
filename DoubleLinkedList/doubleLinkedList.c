#include "doubleLinkedList.h"
#include <assert.h>

_Node_* createNewNode(int value){

	_Node_ *newNode = (_Node_*)malloc(sizeof(_Node_));

	newNode->value = value;
	newNode->prevNode = NULL;
	newNode->nextNode = NULL;

	return newNode;
}

_Node_Details_* createLinkedList(_Node_ *startNode, _Node_Details_ *nodeDetails){

	/*
		Fill in the Node Details for future reference.
		After every addition and deletion of the node , these constructs are updated.
	*/
	nodeDetails->numberOfNodes = 1;
	nodeDetails->headNode = startNode;
	nodeDetails->tailNode = startNode;
	nodeDetails->listStatus = _LIST_OK_;

	return nodeDetails;
}

_Node_Details_* addToHead(_Node_Details_ *nodeDetails, _Node_ *newNode){

	_Node_ *tempNode = (_Node_*)malloc(sizeof(_Node_));

	assert(_FULL_LIST_ != nodeDetails->listStatus);          // Check whether the list is full!!


	tempNode = nodeDetails->headNode;
	
	nodeDetails->headNode = newNode;
	nodeDetails->headNode->nextNode = tempNode;

	nodeDetails->numberOfNodes += 1;

	/*  Update the structure if the list is full */
	if(nodeDetails->numberOfNodes % MAX_NODE == 0)
		nodeDetails-> listStatus = _FULL_LIST_;

	nodeDetails-> listStatus = _LIST_OK_;

	return nodeDetails;
}

_Node_Details_* addToTail(_Node_Details_ *nodeDetails, _Node_ *newNode){

	_Node_ *tempNode = (_Node_*)malloc(sizeof(_Node_));

	assert(_FULL_LIST_ != nodeDetails->listStatus);            // Check whether the list is full!!

	tempNode = nodeDetails->tailNode;	
	nodeDetails->tailNode = newNode;

	nodeDetails->tailNode->prevNode = tempNode;
	tempNode->nextNode = nodeDetails->tailNode;
	
	nodeDetails->numberOfNodes += 1;
	
	/*  Update the structure if the list is full */
	if(nodeDetails->numberOfNodes % MAX_NODE == 0)
		nodeDetails-> listStatus = _FULL_LIST_;

	nodeDetails-> listStatus = _LIST_OK_;

	return nodeDetails;
}

static _Node_Details_* deleteHeadNode(_Node_Details_ *nodeDetails){

	_Node_ *tempNode = (_Node_*)malloc(sizeof(_Node_));

	if(nodeDetails->numberOfNodes == 1){
		tempNode = nodeDetails->headNode;

		nodeDetails->headNode = NULL;
		nodeDetails->tailNode = NULL;
		nodeDetails->listStatus = _EMPTY_LIST_;
		nodeDetails->numberOfNodes -= 1 ;

		free(tempNode);

		return nodeDetails;
	}

	tempNode = nodeDetails->headNode;
	nodeDetails->headNode = nodeDetails->headNode->nextNode;	// Make the next node as head Node.
	nodeDetails->headNode->prevNode = NULL;                     // Since next node becomes head, make prev pointer to point to NULL.

	nodeDetails->numberOfNodes -= 1 ;							// Update the number of Nodes.
	nodeDetails-> listStatus = _LIST_OK_;

	free(tempNode);

	return nodeDetails;
}


static _Node_Details_* deleteTailNode(_Node_Details_ *nodeDetails){

	_Node_ *tempNode = (_Node_*)malloc(sizeof(_Node_));

	/* If that is last node, update the detail structures attributes */
	if(nodeDetails->numberOfNodes == 1){
		tempNode = nodeDetails->tailNode;

		nodeDetails->headNode = NULL;
		nodeDetails->tailNode = NULL;
		nodeDetails->listStatus = _EMPTY_LIST_;
		nodeDetails->numberOfNodes -= 1 ;

		free(tempNode);

		return nodeDetails;
	}


	tempNode = nodeDetails->tailNode;
	nodeDetails->tailNode = nodeDetails->tailNode->prevNode;     // Make previous node as tail Node.
	nodeDetails->tailNode->nextNode = NULL;                      // Update last Node's next pointer to NULL.

	nodeDetails->numberOfNodes -= 1;
	nodeDetails-> listStatus = _LIST_OK_;

	free(tempNode);

	return nodeDetails;
}


_Node_Details_* deleteNode(_Node_Details_ *nodeDetails, int value){


    /* Check whether the list is empty */
	if(_EMPTY_LIST_ == nodeDetails->listStatus){
		printf("Empty List\n");

		return nodeDetails;
	}

	/* If there is only node left then delete the head(which is also the tail) */

	if( 1 == nodeDetails->numberOfNodes){
		nodeDetails = deleteHeadNode(nodeDetails);

		return nodeDetails;
	}

	/* Check whether head node contains the given value*/
	if(value == nodeDetails->headNode->value){
		nodeDetails = deleteHeadNode(nodeDetails);

		return nodeDetails;
	}

	/* Check whether tail node contains the given value*/
	if(value == nodeDetails->tailNode->value){
		nodeDetails = deleteTailNode(nodeDetails);

		return nodeDetails;
	}

	_Node_ *tempNode = (_Node_*)malloc(sizeof(_Node_));

	tempNode = nodeDetails->headNode;

	/* Iterate till you find the node containing the key */
	while(value != tempNode->value )
		tempNode = tempNode->nextNode;

	tempNode->prevNode->nextNode = tempNode->nextNode;             // Make previous node to point to next node of the matched node.
	tempNode->nextNode->prevNode = tempNode->prevNode;			   // Make next node of the macthed node to point to previous node to it.

	nodeDetails->numberOfNodes -= 1;
	nodeDetails-> listStatus = _LIST_OK_;

	free(tempNode);

	return nodeDetails;
}


void displayList(_Node_Details_ *nodeDetails){

	_Node_ *startNode = (_Node_*)malloc(sizeof(_Node_));

	startNode = nodeDetails->headNode;

	while(startNode != NULL){
		printf("[%d]--->",startNode->value);
		startNode = startNode->nextNode;
	}
	printf("\n");
	free(startNode);
}
