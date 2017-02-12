#ifndef _HASH_H
#define _HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct _Node_{

	char element[30];
	struct _Node_ *nextNode;
};

struct _hashTable_{

	uint8_t tableSize;
	struct _Node_ **hashLists;
};

typedef struct _Node_ _Node_;
typedef struct _hashTable_ _hashTable_;

_hashTable_ newHashTable(uint8_t size);
uint8_t findHashTable(_hashTable_ *hTable,char *key);
_hashTable_* insertElement(_hashTable_ *hTable,char *element);

#endif