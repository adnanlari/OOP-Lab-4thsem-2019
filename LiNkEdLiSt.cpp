/****************************************************************
* Name : Adnan Masroor
* Roll : 17CS8053
* Implementation of linked list (using classes and objects)
*****************************************************************/

#include <bits/stdc++.h>
using namespace std;

class SLNode
{
	public:
		int info;
		SLNode *next;

	SLNode()
	{
		info=0;
		next=NULL;
		//cout<<"SLNode Constructor 1!\n";
	}
	SLNode(int x,SLNode *p)
	{
		info=x;
		next=p;
		//cout<<"SLNode Constructor 2!\n";
	}
	/*~SLNode()
	{
		cout<<"SLNode Destructor!\n";
	}*/

};

class SLL
{
	public:
		SLNode *head;
		int count;

	SLL()
	{
		head=NULL;
		count=0;
		//cout<<"List Creation 1!\n";
	}
	SLL(SLNode *p,int x)
	{
		head=p;
		count=x;
		//cout<<"List Craetion 2!\n";
	}

	void insbeg(int x);
	void delbeg();
	bool search(int x);
	void display();
	void delend();
	void delmid(int i);
	void insend(int x);
	void insmid(int x,int i);
	~SLL()
	{
		SLNode *p=head;
		while(p!=NULL)
		{
			head=p->next;
			delete[] p;
			p=head;

		}
		//cout<<"List Destructor!\n";
	}
};

void SLL::insbeg(int x)
{
	head=new SLNode(x,head);
	count++;
	//cout<<x<<" has been inserted!\n";
}

void SLL::delbeg()
{
	if(!count)
	{
		cout<<"Underflow!\n";
		return;
	}
	SLNode* temp=head;
	head=head->next;
	//cout<<temp->info<<" has been deleted!\n";
	delete[] temp;
	count--;
}

bool SLL::search(int x)
{
	SLNode *temp=head;
	while(temp!=NULL)
	{
		if(temp->info == x)
			return true;
		temp=temp->next;
	}
	return false;
}

void SLL::display()
{
	cout<<"["<<count<<"]"<<"->";
	SLNode *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->info<<"->";
		temp=temp->next;
	}
	cout<<"|||---\n";
}

void SLL::delend()
{
	SLNode *temp=head;
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
	SLNode *a=temp->next;
	temp->next=NULL;
	count--;
	delete [] a;
}
void SLL::insend(int x)
{
	SLNode *temp=new SLNode(x,NULL);
	SLNode *t=head;
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


int main()
{
	SLL my_list;
	cout<<setw(30)<<setfill('*')<<"MENU"<<setw(27)<<"\n";
	cout<<"1.Display\n2.Insert at Beginning\n3.Insert at End\n4.Delete from Beginning\n5.Delete from end\n6.Search for an element\n7.Exit"<<"\n"<<setw(59)<<"\n\n\n";
	int ch,a;
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
				my_list.display();
			break;
			case 2:
				cout<<"Enter a value to be inserted : ";
				cin>>a;
				my_list.insbeg(a);
			break;
			case 3:
				cout<<"Enter a value to be inserted : ";
				cin>>a;
				my_list.insend(a);
			break;
			case 4:
				my_list.delbeg();
			break;
			case 5:
				my_list.delend();
			break;
			case 6:
				cout<<"Enter the element to be searched : ";
				cin>>a;
				if(my_list.search(a))
					cout<<"succesful!\n";
				else
					cout<<"unsuccesful!\n";
			break;
			default:
				cout<<"Invalid Choice!\n";


		}
		cout<<"\n";
	}
}