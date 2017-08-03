#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;

};

node *front = NULL, *rear = NULL;


void push( int value)
{

node* temp = new node;
node* prev = new node;
temp->data = value;
temp->next = NULL;

if(front == NULL)
{
	front = rear =  temp;
	rear->next = NULL;
}

else
{
	rear->next = temp;
	rear = temp;
	rear->next = NULL;
}

}


int remove(){
	int x;
	node* temp = new node;
	if (front == NULL)
	{
		cout<<"Empty Queue "<<endl;
	}

	else
	{
		temp = front;
		x = temp->data;
		front = front->next;
		delete(temp);
	}
	return x;

}






void main()
{

	int n,c = 0,x;
    cout<<"Enter the number of values to be pushed into queue\n";
    cin>>n;
    while (c < n)
    {
	cout<<"Enter the value to be entered into queue\n";
	cin>>x;
        push(x);
        c++;
     }
     cout<<"\n\nRemoved Values\n\n";
     while(true)
     {
        if (front != NULL)
            cout<<remove()<<endl;
        else
            break;
     }
	// return 0;
	getchar();

}