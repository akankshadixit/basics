#include "stdafx.h"
#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

hashT::hashT(){
   
	for(int i =0; i<tableSize ;i++)
	{
		hashTable[i] = new item;
		hashTable[i]->name  = "empty";
		hashTable[i]->drink = "empty";
		hashTable[i]->next  = NULL;
	}
}

void hashT::AddItem(string name, string drink){

	int index = Hash(name);

	if(hashTable[index]->name == "empty")
	{ 
		hashTable[index]->name = name;
		hashTable[index]->drink = drink;
	}
	else
	{
		item* ptr = hashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = n;
	}

}

void hashT::PrintTable(){

     int number;
	 for (int i = 0; i < tableSize; i++)
	 {
		 number = NumberOfItemsInIndex(i);
		 cout<<"-----------------------------"<<endl;
		 cout<<"index = "<<i<<endl;
		 cout<<hashTable[i]->name<<endl;
		 cout<<hashTable[i]->drink<<endl;
		 cout<<"# of items = "<<number<<endl;
		 cout<<"------------------------------"<<endl;
	 }
}

void hashT::PrintItemsInIndex(int index)
{
	item* ptr = hashTable[index];
	if (ptr->name == "empty")
	{
		cout<<"index = "<<index <<" is empty"<<endl;

	}
	else
	{
	   cout<<"index = "<<index<<" contains the following items"<<endl;
       while (ptr != NULL)
	   {
		    cout<<"------------------------------"<<endl;
			cout<<ptr->name <<endl;
			cout<<ptr->drink<<endl;
			cout<<"--------------------------------"<<endl;
			ptr = ptr->next;
	   }
	}
	

}

int hashT::NumberOfItemsInIndex(int index)
{

	int count = 0;
	if(hashTable[index]->name == "empty")
	{
		return count;
	}
	else 
	{
	count++;
	item* ptr = hashTable[index];
	while (ptr->next != NULL)
	{
		 count++;
		 ptr = ptr->next;
	}

	return count;
}
}

int hashT::Hash (string key)
{

	int hash = 0;
	int index;

	for(int i =0; i<key.length(); i++)
	{
		hash = hash +(int)key[i];
		
	}

	index = hash % tableSize;

	return index;

}

void hashT::FindDrink(string name)
{
	int index = Hash(name);
	bool foundName = false;
	string drink;
	item* ptr = hashTable[index];

	while (ptr != NULL)
	{
		if(ptr->name == name)
		{
			foundName = true;
			drink = ptr->drink;
		}
		ptr = ptr->next;
	}

	if(foundName == true)
	{
	
		cout<<"Favourite drink = "<<drink<<endl;
	}
	else
	{
		cout<<name<<"'s info was not found in the hash table"<<endl;
	}

}

void hashT::RemoveItem(string name)
{
	int index= Hash(name);
	item* delPtr;
	item* P1;
	item* P2;

	//case 0 - bucket is empty

	if(hashTable[index]->name == "empty" && hashTable[index]->drink == "empty" )
	{
	 cout<<name << " was not found in the table"<<endl;
	}


	//case 1 - only 1 item in the bucket and that is the item we are looking for

	else if(hashTable[index]->name == name && hashTable[index]->next == NULL)
	{
		hashTable[index]->name = "empty";
		hashTable[index]->drink = "empty";
		cout<< name <<" was removed from the table"<<endl;
	}

	//case 2 - match is located in the first item but there are more items in the bucket

	else if(hashTable[index]->name == name)
	{
		delPtr = hashTable[index];
		hashTable[index] = hashTable[index]->next;
		delete delPtr;
		cout<< name <<" was removed from the table"<<endl;
	}

	//case 3 - bucket contains the item but first item is not the match

	else 
	{
		P1 = hashTable[index]->next;
		P2 = hashTable[index];

		while (P1 != NULL && P1->name != name)
		{
			P2 = P1;
			P1 = P1->next;
		}
			//case 3.1 - no match
		if(P1 == NULL)
		{
		   cout<< name << " was not found in the table"<<endl;
		}
		//case 3.2 - match is found

		else
		{
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;

			delete delPtr;
		    cout<< name <<" was removed from the table"<<endl;
		}
	}

	


}