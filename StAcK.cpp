/***********************************************************
* Name : Adnan Masroor 
* Roll : 17CS8053
* Implementation : Stack using classes in C++
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

template <typename T>
class Stack
{
	public:
		int top;
		T *A=new T[MAX];

		Stack()
		{
			top=-1;
		}

		void push(T x);
		void pop();
		void display();

		~Stack()
		{
			cout<<"Stack has been dissoved!\nThank You!!\n";
			delete(A);
		}
};

template <typename T>
void Stack<T>::push(T x)
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
template <typename T>
 void Stack<T>::pop()
{
	if(top==-1)
		cout<<"Underflow!\n";
	else
	{
		cout<<(*(A+top))<<" has been popped from the stack!\n";
		--top;
	}
}
template <typename T>
 void Stack<T>::display()
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
	Stack<string> my_s;
	cout<<"**********MENU**********\n1.Display\n2.Push\n3.Pop\n4.Exit\n";
	int ch;
	string x;
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