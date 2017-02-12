#include "hash.h"

/* Create new OpenHashing Table */

_hashTable_ newHashTable(uint8_t size){

	_hashTable_ hTable;

	hTable.tableSize = size;
	hTable.hashLists = (hashLists**)calloc(sizeof(hashLists*)*hTable.tableSize);   

}

/* Hash Function */

static uint8_t _hash_(char *key, uint8_t size){

	int hashValue;

	while(*key != '\0')
		hashValue = *key++ + hashValue << 5;         // Random logic to index the table.

	return (hashValue % size);						
}	


uint8_t findHashTable(_hashTable_ *hTable,char *key){

	_Node_ *temp = hTable[_hash_(key,hTable->tableSize)];   // Look for the key in matched index list.

	while(NULL != temp){

		if(!strcmp(temp->element,key))
			break;

		else
			temp = temp->nextNode;
	}

	return (NULL!=temp);                            // Returns true if matches with key.
}

_hashTable_* insertElement(_hashTable_ *hTable,char *element){

	/* To Be Done */

}


