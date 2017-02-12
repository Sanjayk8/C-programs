#include "doubleLinkedList.h"

int main(){

	_Node_ *node ;
	_Node_Details_ *nodeDetails = (_Node_Details_*)malloc(sizeof(_Node_Details_));

	node = createNewNode(10);
	nodeDetails = createLinkedList(node,nodeDetails);

	node = createNewNode(20);
	nodeDetails = addToHead(nodeDetails,node);

	node = createNewNode(30);
	nodeDetails = addToTail(nodeDetails,node);

	node = createNewNode(40);
	nodeDetails = addToTail(nodeDetails,node);

	node = createNewNode(50);
	nodeDetails = addToHead(nodeDetails,node);

	//node = createNewNode(60);
	//nodeDetails = addToHead(nodeDetails,node);

	displayList(nodeDetails);

	nodeDetails = deleteNode(nodeDetails,50);

	displayList(nodeDetails);

	nodeDetails = deleteNode(nodeDetails,30);

	displayList(nodeDetails);

	printf("NumberOfNodes:%d\nHeadNode:%d\nTailNode:%d,ListStatus:%d\n",nodeDetails->numberOfNodes,nodeDetails->headNode->value,
		nodeDetails->tailNode->value,nodeDetails->listStatus );

	nodeDetails = deleteNode(nodeDetails,20);

	displayList(nodeDetails);

	nodeDetails = deleteNode(nodeDetails,10);

	displayList(nodeDetails);

	nodeDetails = deleteNode(nodeDetails,10);

	displayList(nodeDetails);

	nodeDetails = deleteNode(nodeDetails,40);

	displayList(nodeDetails);

	printf("NumberOfNodes:%d\nListStatus:%d\n",nodeDetails->numberOfNodes,nodeDetails->listStatus );

	free(nodeDetails);
}