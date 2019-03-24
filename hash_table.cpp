/****************************************************************
* Name : Adnan Masroor
* Roll : 17CS8053
* Implementation of hash table and open chaining (using linked list and class)
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


class Hash
{
	public:
		SLL *H;
		int M;

	Hash(int x)
	{
		H=new SLL[x];
		M=x;
	}
	
	void Hash_insert(int x,int val);
	void Hash_display();
};

void Hash::Hash_insert(int x,int val)
{
	H[x].insbeg(val);
}

void Hash::Hash_display()
{
	for(int i=0;i<M;i++)
	{
		cout<<"Index : "<<i<<" = ";
		H[i].display();
	}
}

int main()
{
	Hash HS(10);

	srand(time(0));

	for(int i=0;i<20;i++)
	{
		int val=rand();
		HS.Hash_insert(val%10,val);
	}
	HS.Hash_display();

	SLL a;
	a.insbeg(23);
	a.insbeg(56);
	a.insbeg(78);
	a.insbeg(13);
	a.display();
	cout<<a.search(56)<<"\n"<<a.search(67)<<"\n";
	a.delend();
	a.display();
	a.delend();
	a.display();
	a.delend();
	a.display();
	a.delend();
	a.display();
	a.delend();
	a.display();
	a.insend(89);
	a.insend(147);
	a.display();

	return 0;

	return 0;

}