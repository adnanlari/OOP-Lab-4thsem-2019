/*******************************************
* AUTHOR : Adnan Masroor :-)
* NICK : adnanlari
* COLLEGE : NIT Durgapur
* Implement Buddy List
********************************************/


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
	bool isEmpty();
	int F();

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

int SLL::F()
{
	return head->info;
}

bool SLL::isEmpty()
{
	if(head==NULL)
		return true;
	else
		return false;
}

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
	bool hisempty(int x);
	void Del(int x);
	int HF(int x);
	void Hash_display();
};

int Hash::HF(int x)
{
	return H[x].F();
}

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
void Hash::Del(int x)
{
	H[x].delbeg();
}

bool Hash::hisempty(int x)
{
	if(H[x].isEmpty())
		return true;
	else
		return false;
}


int main()
{
	Hash H(11);
	H.Hash_insert(10,0);
	vector <pair<int,int>> V;
	for(int j=0;j<5;j++)
	{
		int n;
		cin>>n;

		n=ceil(log(n)/log(2));
		int i=n;

		while(H.hisempty(i))
			i++;
		while(pow(2,i)!=pow(2,n))
		{
			int x=H.HF(i);
			H.Del(i);
			H.Hash_insert(i-1,x+pow(2,i-1));
			H.Hash_insert(i-1,x);
			i--;
		}
		int y=H.HF(i);
		V.push_back(make_pair(y,y+pow(2,i)-1));
		H.Del(i);
	}
	for(int i=0;i<5;i++)
		cout<<V[i].first<<" "<<V[i].second<<"\n";
		H.Hash_display();


}

