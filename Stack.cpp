#include "stdafx.h"
#include <iostream>
using namespace std;


struct node{

	int data;
	node *next;

};

node *top;

class stack{

public:

	stack()
	{
	
		top = NULL;
	}
	node* push(node*, int);
	node* pop(node*);
	void traverse(node*);


};

node* stack::push(node *top, int value)
{
   node* temp  = new node;
   temp->data = value;
   temp->next = top;
   top = temp;
   return top;
}

node* stack::pop (node *top){

	node *temp = new node;
	if(top == NULL)
	{
	 cout<<"Stack is empty "<<endl;
	
	}
	else
	{
	  temp = top;
	  top = top->next;
	  free(temp);
	}

	return top;
}

void stack::traverse(node *top){

node *temp = new node;
temp = top;
if(top == NULL)
{
cout<<"Stack is empty "<<endl;
}
else
{
	while (top != NULL)
	{
		cout << temp->data <<endl;
		temp = temp->next;
	}
}


}

int main(){

	int choice, item;
	stack sl;
    while (1)
    {
        cout<<"\n-------------"<<endl;
        cout<<"Operations on Stack"<<endl;
        cout<<"\n-------------"<<endl;
        cout<<"1.Push Element into the Stack"<<endl;
        cout<<"2.Pop Element from the Stack"<<endl;
        cout<<"3.Traverse the Stack"<<endl;
        cout<<"4.Quit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be pushed into the stack: ";
            cin>>item;
            top = sl.push(top, item);
            break;
        case 2:
            top = sl.pop(top);
            break;
        case 3:
            sl.traverse(top);
            break;
        case 4:
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
	getchar();


}