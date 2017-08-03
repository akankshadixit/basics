#include "stdafx.h"
#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

int main(){

	hashT hashy;
	string name = "";

	hashy.AddItem("Akanksha", "lassi");
	hashy.AddItem("Anketa", "chach");
	hashy.AddItem("harsh", "milk");
	hashy.AddItem("vijaya", "tea");
	hashy.AddItem("sangita", "coffee");
	hashy.AddItem("jyoti", "water");
	hashy.AddItem("poonam", "cola");
	hashy.AddItem("aditya", "beer");
	hashy.AddItem("arjun", "soup");
	hashy.AddItem("uma", "whiskey");

	hashy.PrintTable();
	//hashy.PrintItemsInIndex(8);

	while (name != "exit")
	{
		cout<<"Remove ";
		cin>>name;
		if(name != "exit")
		{
			hashy.RemoveItem(name);
		}
	}
	hashy.PrintTable();
	getchar();

}