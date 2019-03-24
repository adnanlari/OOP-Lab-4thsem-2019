/***********************************************************
* Name : Adnan Masroor 
* Roll : 17CS8053
* Implementation : Stack using classes in C++
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack
{
	public:
		int top;
		int *A=new int[MAX];

		Stack()
		{
			top=-1;
			for(int i=0;i<MAX;i++)
				*(A+i)=0;
		}

		void push(int x);
		void pop();
		void display();

		~Stack()
		{
			cout<<"Stack has been dissoved!\nThank You!!\n";
			delete(A);
		}
};
 void Stack::push(int x)
{
	if(top==MAX-1)
		cout<<"Overflow!\n";
	else
	{
		++top;
		*(A+top)=x;
		cout<<x<<" has been pushed into the stack!\n";
	}
}
 void Stack::pop()
{
	if(top==-1)
		cout<<"Underflow!\n";
	else
	{
		cout<<(*(A+top))<<" has been popped from the stack!\n";
		*(A+top)=0;
		--top;
	}
}
 void Stack::display()
{
	if(top==-1)
		cout<<"Stack is Empty!\n";
	else
	{
		cout<<"Stack :\n";
		for(int i=0;i<=top;i++)
			cout<<*(A+i)<<" ";
		cout<<"\n";
	}
}

int main()
{
	Stack my_s;
	cout<<"**********MENU**********\n1.Display\n2.Push\n3.Pop\n4.Exit\n";
	int ch,x;
	while(1)
	{
		cout<<"Enter your choice : ";
		cin>>ch;
		if(ch==4)
			break;
		switch(ch)
		{
			case 1:
				my_s.display();
				break;
			case 2:
				cout<<"Enter the element : ";
				cin>>x;
				my_s.push(x);
				break;
			case 3:
				my_s.pop();
				break;
			default:
				cout<<"Invalid choice!\n ";


		}
	}
	return 0;
}