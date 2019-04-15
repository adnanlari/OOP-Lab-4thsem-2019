/***********************************************************
* Name : Adnan Masroor 
* Roll : 17CS8053
* Implementation : Queue using classes in C++
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

template <typename T>
class Queue
{
	public:
		int l,r;
		T *A=new T[MAX];

		Queue()
		{
			l=r=-1;
		}

		void push(T x);
		void pop();
		void display();

		~Queue()
		{
			cout<<"Queue has been dissoved!\nThank You!!\n";
			delete(A);
		}
};

template <typename T>
void Queue<T>::push(T x)
{
	if(r==MAX-1)
		cout<<"Overflow!\n";
	else if(l==r && l==-1)
		l=r=0;
	else
		++r;
	*(A+r)=x;
	cout<<x<<" has been pushed into the Queue!\n";
}
template <typename T>
 void Queue<T>::pop()
{
	if(l==r && l==-1)
		cout<<"Underflow!\n";
	else if(l==r && l!=-1)
	{
		cout<<(*(A+l))<<" has been popped from the Queue!\n";
		l=r=-1;
	}
	else
	{
		cout<<(*(A+l))<<" has been popped from the Queue!\n";
		++l;
	}
}
template <typename T>
 void Queue<T>::display()
{
	if(l==r && l==-1)
		cout<<"Queue is Empty!\n";
	else
	{
		cout<<"Queue :\n";
		for(int i=l;i<=r;i++)
			cout<<*(A+i)<<" ";
		cout<<"\n";
	}
}
int main()
{
	Queue<float> my_s;
	cout<<"**********MENU**********\n1.Display\n2.Push\n3.Pop\n4.Exit\n";
	int ch;
	float x;
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