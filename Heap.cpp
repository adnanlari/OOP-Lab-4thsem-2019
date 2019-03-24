/*************************************************************
* Name : Adnan Masroor
* Roll : 17CS8053
* Implementation of heap suing class and objects.
*************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Heap
{
public:
	int *H;
	int p;
	Heap()
	{
		H=new int[MAX];
		p=0;
	}
	void ghusao(int x);
	void dikhao();
	int nikalo();
	int daye(int i) { return i+i+2; }
	int baye(int i) { return i+i+1; }
	void Heapify(int i);
	~Heap()
	{
		delete [] H;
		p=0;
	}

};

void Heap::ghusao(int x)
{
	*(H+p)=x;
	int i=p,count=0;
	p+=1;
	while(*(H+((i-1)/2)) < *(H+i))
	{
		int temp=*(H+((i-1)/2));
		*(H+((i-1)/2))=*(H+i);
		*(H+i)=temp;
		count++;
		i=(i-1)/2;
	}
}

void Heap::dikhao()
{
	int i=0,q=1;
	if(!p)
	{
		cout<<"Heap Empty!\n";
		return;
	}
	while(i<p)
	{
		int j=0;
		while(j<q && i<p)
		{
			cout<<*(H+i)<<" ";
			i++;
			j++;
		}
		q*=2;
		cout<<"\n";

	}
}

int Heap::nikalo()
{
	int x=*H;
	*H=*(H+p-1);
	--p;
	Heap::Heapify(0);
	return x;
}

void Heap::Heapify(int i)
{
	int l=baye(i),r=daye(i),g=i;
	if(l<p && *(H+l)>*(H+g))
		g=l;
	if(r<p && *(H+r)>*(H+g))
		g=r;
	if(g!=i)
	{
		int x=*(H+i);
		*(H+i)=*(H+g);
		*(H+g)=x;
		Heap::Heapify(g);
	}

}


int main()
{
	cout<<"****************MENU*****************\n1.Insert\n2.Delete\n3.Display\n4.Exit\n*************************************\n";

	Heap myH;
	int val,ch;

	while(1)
	{
		cout<<"Enter Your Choice : ";
		cin>>ch;
		if(ch==4)
		{
			cout<<"Thank You!\n";
			break;
		}
		switch(ch)
		{
			case 1:
				cout<<"Enter the element : ";
				cin>>val;
				myH.ghusao(val);
			break;
			case 2:
				cout<<"Maximum Element : ";
				cout<<myH.nikalo()<<"\n";
			break;
			case 3:
				myH.dikhao();
			break;
			default:
				cout<<"invalid Input!\n";
		}

	}

	return 0;
}
