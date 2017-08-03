#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class hashT
{
private:
	static const int tableSize = 4;

	struct item{
	
		 string name;
		 string drink;
		 item * next;
	};

	item *hashTable[tableSize];

public:

	hashT();
	int Hash (string key);
	void AddItem(string name, string drink);
	int NumberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void FindDrink(string name);
	void RemoveItem(string name);

	
};
