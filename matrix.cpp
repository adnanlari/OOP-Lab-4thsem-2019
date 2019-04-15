/*************************************************************
* Name : Adnan Masroor 
* Roll : 17CS8053
* Implementation of matrix using operator overloading
* and copy constructor. 
*************************************************************/


#include <bits/stdc++.h>
using namespace std;
template <typename T>
class mat
{
public:
	int size;
	T **A;
	mat(int s=0)
	{
		size=s;
		A=new T* [size];
		for(int i=0;i<size;i++)
			*(A+i)=new T[size];
		cout<<"Input "<<size<<"*"<<size<<" elements : \n";
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
				cin>>*(*(A+j)+i);
		}
	}
	mat(mat<T> const &x)
	{
		size=x.size;
		A=new T* [size];
		for(int i=0;i<size;i++)
			*(A+i)=new T[size];
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
				*(*(A+j)+i)=*(*(x.A+j)+i);
		}

	}

	friend mat<T> operator + (mat<T> const &a,mat<T> const &b)
	{
		mat<T> c=a;
		for(int i=0;i<c.size;i++)
		{
			for(int j=0;j<c.size;j++)
				*(*(c.A+j)+i)=*(*(c.A+j)+i)+*(*(b.A+j)+i);
		}
		return c;


	}
	friend mat<T> operator - (mat<T> const &a,mat<T> const &b)
	{
		mat<T> c=a;
		for(int i=0;i<c.size;i++)
		{
			for(int j=0;j<c.size;j++)
				*(*(c.A+j)+i)=*(*(c.A+j)+i)-*(*(b.A+j)+i);
		}
		return c;


	}
	friend mat<T> operator * (mat<T> const &a,mat<T> const &b)
	{
		mat<T> c=a;
		for(int i=0;i<c.size;i++)
		{
			for(int j=0;j<c.size;j++)
			{
				T x=0;
				for(int k=0;k<c.size;k++)
					x+=(*(*(a.A+k)+i))*(*(*(b.A+j)+k));
				*(*(c.A+j)+i)=x;
			}
		}
		return c;
	}
	friend void operator ++ (mat<T> &a)
	{
		for(int i=0;i<a.size;i++)
		{
			for(int j=0;j<a.size;j++)
			{
				(*(*(a.A+j)+i))+=1.0;
			}
		}
	}
	friend void operator -- (mat<T> &a)
	{
		for(int i=0;i<a.size;i++)
		{
			for(int j=0;j<a.size;j++)
			{
				(*(*(a.A+j)+i))-=1.0;
			}
		}
	}

	friend mat<T> operator - (mat<T> const &a)
	{
		mat<T> c=a;
		for(int i=0;i<a.size;i++)
		{
			for(int j=0;j<a.size;j++)
			{
				*(*(c.A+j)+i)=-(*(*(a.A+j)+i));
			}
		}
		return c;
	}
	friend mat<T> operator ~ (mat<T> const &a)
	{
		mat<T> c=a;
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
	mat<float> a(2),b(2);
	mat<float> c=a+b;
	c.dikha();
	cout<<"\n";
	c=a-b;
	c.dikha();
	cout<<"\n";
	c=a*b;
	c.dikha();
	cout<<"\n";
	++c;
	c.dikha();
	cout<<"\n";
	--c;
	c.dikha();
	cout<<"\n";
	c=-c;
	c.dikha();
	cout<<"\n";
	c=~c;
	c.dikha();

}

