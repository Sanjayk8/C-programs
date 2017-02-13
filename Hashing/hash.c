#include "hash.h"

/* Create new OpenHashing Table */

_hashTable_* newHashTable(uint8_t size){

	_hashTable_ *hTable = (_hashTable_*)malloc(sizeof(_hashTable_));

	hTable->tableSize = size;
	hTable->hashLists = (_Node_**)malloc(sizeof(_Node_*)*hTable->tableSize);  

	return hTable; 

}

/* Hash Function */

static uint8_t _hash_(char *key, uint8_t size){

	int hashValue;

	while(*key != '\0')
		hashValue = *key++ + hashValue << 5;         // Random logic to index the table.

	return (hashValue % size);						
}	


uint8_t findHashTable(_hashTable_ *hTable,char *key){

	_Node_ *temp = hTable->hashLists[_hash_(key,hTable->tableSize)];   // Look for the key in matched index list.

	while(NULL != temp){

		if(!strcmp(temp->element,key))
			break;

		else
			temp = temp->nextNode;
	}

	return (NULL!=temp);                            // Returns true if matches with key.
}

_hashTable_* insertElement(_hashTable_ *hTable,char *element){

	_Node_ *oldAdress;

	uint8_t bucket = _hash_(element,hTable->tableSize);          // Hash the element to make it key to the hashLists.  

	if(!findHashTable(hTable,element)){                          // Check whether the key is already present.
		oldAdress = hTable->hashLists[bucket];
		hTable->hashLists[bucket] = (_Node_*)malloc(sizeof(_Node_));
		strcpy(hTable->hashLists[bucket]->element,element);

		hTable->hashLists[bucket]->nextNode = oldAdress;         // Add to the head, hence make the previous node as next node.
	}

	return hTable;
}


