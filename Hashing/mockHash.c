#include "hash.h"

int main(){

	_hashTable_ *hash;

	hash = newHashTable(10);
	hash = insertElement(hash,"Tom");
	hash = insertElement(hash,"Jerry");
	hash = insertElement(hash,"Peter");

	if(findHashTable(hash,"Jerry"))
		printf("Key is present in hash table!!\n");

	if(!findHashTable(hash,"hello")){
		printf("Not present!\n");
	}
}