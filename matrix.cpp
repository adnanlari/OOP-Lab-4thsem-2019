/*************************************************************
* Name : Adnan Masroor 
* Roll : 17CS8053
* Implementation of matrix using operator overloading
* and copy constructor. 
*************************************************************/


#include <bits/stdc++.h>
using namespace std;

class mat
{
public:
	int size;
	int **A;
	mat(int s=0)
	{
		size=s;
		A=new int* [size];
		for(int i=0;i<size;i++)
			*(A+i)=new int[size];
		cout<<"Input "<<size<<"*"<<size<<" elements : \n";
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
				cin>>*(*(A+j)+i);
		}
	}
	mat(mat const &x)
	{
		size=x.size;
		A=new int* [size];
		for(int i=0;i<size;i++)
			*(A+i)=new int[size];
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
				*(*(A+j)+i)=*(*(x.A+j)+i);
		}

	}

	friend mat operator + (mat const &a,mat const &b)
	{
		mat c=a;
		for(int i=0;i<c.size;i++)
		{
			for(int j=0;j<c.size;j++)
				*(*(c.A+j)+i)=*(*(c.A+j)+i)+*(*(b.A+j)+i);
		}
		return c;


	}
	friend mat operator - (mat const &a,mat const &b)
	{
		mat c=a;
		for(int i=0;i<c.size;i++)
		{
			for(int j=0;j<c.size;j++)
				*(*(c.A+j)+i)=*(*(c.A+j)+i)-*(*(b.A+j)+i);
		}
		return c;


	}
	friend mat operator * (mat const &a,mat const &b)
	{
		mat c=a;
		for(int i=0;i<c.size;i++)
		{
			for(int j=0;j<c.size;j++)
			{
				int x=0;
				for(int k=0;k<c.size;k++)
					x+=(*(*(a.A+k)+i))*(*(*(b.A+j)+k));
				*(*(c.A+j)+i)=x;
			}
		}
		return c;
	}
	friend void operator ++ (mat &a)
	{
		for(int i=0;i<a.size;i++)
		{
			for(int j=0;j<a.size;j++)
			{
				++(*(*(a.A+j)+i));
			}
		}
	}
	friend void operator -- (mat &a)
	{
		for(int i=0;i<a.size;i++)
		{
			for(int j=0;j<a.size;j++)
			{
				--(*(*(a.A+j)+i));
			}
		}
	}

	friend mat operator - (mat const &a)
	{
		mat c=a;
		for(int i=0;i<a.size;i++)
		{
			for(int j=0;j<a.size;j++)
			{
				*(*(c.A+j)+i)=-(*(*(a.A+j)+i));
			}
		}
		return c;
	}
	friend mat operator ~ (mat const &a)
	{
		mat c=a;
		for(int i=0;i<a.size;i++)
		{
			for(int j=0;j<a.size;j++)
			{
				*(*(c.A+i)+j)=-(*(*(a.A+j)+i));
			}
		}
		return c;
	}


	void dikha()
	{
		cout<<"Size : "<<size<<"\n";
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
				cout<<*(*(A+j)+i)<<" ";
			cout<<"\n";
		}

	}
};
int main()
{
	mat a(3),b(3);
	mat c=a+b;
	c.dikha();
	c=a-b;
	c.dikha();
	c=a*b;
	c.dikha();
	++c;
	c.dikha();
	--c;
	c.dikha();
	c=-c;
	c.dikha();
	c=~c;
	c.dikha();

}

