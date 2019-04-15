/****************************************************************
* Name : Adnan Masroor
* Roll : 17CS8053
* Implementation of linked list (using classes and objects)
*****************************************************************/

#include <bits/stdc++.h>
using namespace std;
template <typename T>
class SLNode
{
	public:
		T info;
		SLNode *next,*prev;

	SLNode()
	{
		info=0;
		prev=next=NULL;
		//cout<<"SLNode Constructor 1!\n";
	}
	SLNode(T x,SLNode<T> *p)
	{
		info=x;
		next=p;
		prev=NULL;
		//cout<<"SLNode Constructor 2!\n";
	}
	/*~SLNode()
	{
		cout<<"SLNode Destructor!\n";
	}*/

};
template <typename T>
class SLL
{
	public:
		SLNode<T> *head;
		int count;

	SLL()
	{
		head=NULL;
		count=0;
		//cout<<"List Creation 1!\n";
	}
	SLL(SLNode<T> *p,int x)
	{
		head=p;
		count=x;
		//cout<<"List Craetion 2!\n";
	}

	void insbeg(T x);
	void delbeg();
	bool search(T x);
	void display();
	void delend();
	//void delmid(int i);
	void insend(T x);
	//void insmid(int x,int i);
	~SLL()
	{
		SLNode<T> *p=head;
		while(p!=NULL)
		{
			head=p->next;
			delete[] p;
			p=head;

		}
		//cout<<"List Destructor!\n";
	}
};
template <typename T>
void SLL<T>::insbeg(T x)
{
	head=new SLNode<T>(x,head);
	count++;
	//cout<<x<<" has been inserted!\n";
}
template <typename T>
void SLL<T>::delbeg()
{
	if(!count)
	{
		cout<<"Underflow!\n";
		return;
	}
	SLNode<T>* temp=head;
	head=head->next;
	//cout<<temp->info<<" has been deleted!\n";
	delete[] temp;
	count--;
}
template <typename T>
bool SLL<T>::search(T x)
{
	SLNode<T> *temp=head;
	while(temp!=NULL)
	{
		if(temp->info == x)
			return true;
		temp=temp->next;
	}
	return false;
}
template <typename T>
void SLL<T>::display()
{
	cout<<"["<<count<<"]"<<"->";
	SLNode<T> *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->info<<"->";
		temp=temp->next;
	}
	cout<<"|||---\n";
}
template <typename T>
void SLL<T>::delend()
{
	SLNode<T> *temp=head;
	if(count==0)
	{
		cout<<"Underflow!\n";
		return;
	}
	else if(count==1)
	{
		head=NULL;
		count--;
		return;
	}

	while(temp->next->next!=NULL)
		temp=temp->next;
	SLNode<T> *a=temp->next;
	temp->next=NULL;
	count--;
	delete [] a;
}
template <typename T>
void SLL<T>::insend(T x)
{
	SLNode<T> *temp=new SLNode<T>(x,NULL);
	SLNode<T> *t=head;
	if(count==0)
		head=temp;
	else
	{
		while(t->next!=NULL)
			t=t->next;
		t->next=temp;
	}
	count++;
}


template <typename T>
class DLL : public SLL<T>
{
	public:
		// SLNode<T> *prev;
		SLNode<T> *tail;
	DLL()
	{
		tail=NULL;
		
	}
	void insert_beg(T x)
	{
		SLNode<T> *temp=new SLNode<T>(x,NULL);
		temp->next=(SLL<T>::head);
		temp->prev=NULL;
		if((SLL<T>::head)==NULL)
		{
			(SLL<T>::head)=temp;
			tail=temp;
		}
		else
			(SLL<T>::head)->prev=temp;
		SLL<T>::head=temp;
		(SLL<T>::count)+=1;
		
	}
	void insert_end(T x)
	{
		SLNode<T> *temp=new SLNode<T>(x,NULL);
		temp->next=NULL;
		temp->prev=tail;
		if(tail==NULL)
		{
			tail=temp;
			(SLL<T>::head)=temp;
		}
		else
			tail->next=temp;
		tail=temp;
		(SLL<T>::count)+=1;
		
	}
	void dekhe()
	{
		SLL<T>::display();
	}





};

int main()
{
	DLL<int> my_list;
	cout<<setw(30)<<setfill('*')<<"MENU"<<setw(27)<<"\n";
	cout<<"1.Display\n2.Insert at Beginning\n3.Insert at End\n4.Delete from Beginning\n5.Delete from end\n6.Search for an element\n7.Exit"<<"\n"<<setw(59)<<"\n\n\n";
	int ch;
	float a;
	while(1)
	{
		cout<<"Enter your choice : ";
		cin>>ch;
		if(ch==7)
		{
			cout<<"Thankyou!\n";
			break;
		}
		switch(ch)
		{
			case 1:
				my_list.dekhe();
			break;
			case 2:
				cout<<"Enter a value to be inserted : ";
				cin>>a;
				my_list.insert_beg(a);
			break;
			case 3:
				cout<<"Enter a value to be inserted : ";
				cin>>a;
				my_list.insert_end(a);
			break;
			// case 4:
			// 	my_list.delbeg();
			// break;
			// case 5:
			// 	my_list.delend();
			// break;
			// case 6:
			// 	cout<<"Enter the element to be searched : ";
			// 	cin>>a;
			// 	if(my_list.search(a))
			// 		cout<<"succesful!\n";
			// 	else
			// 		cout<<"unsuccesful!\n";
			// break;
			default:
				cout<<"Invalid Choice!\n";


		}
		cout<<"\n";
	}
}