/*************************************************************
* Name : Adnan Masroor 
* Roll : 17CS8053
* Implementation of complex numbers using operator overloading
* and copy constructor. 
*************************************************************/


#include <bits/stdc++.h>
using namespace std;

class comp
{
public:
	int real,imag;
	comp(int r=0,int i=0)
	{
		real=r;
		imag=i;
	}

	comp(comp const &x)
	{
		real=x.real;
		imag=x.imag;
	}

	friend comp operator + (comp const &x,comp const &y)
	{
		return comp(x.real+y.real,x.imag+y.imag);

	}
	friend comp operator - (comp const &x,comp const &y)
	{
		return comp(x.real-y.real,x.imag-y.imag);

	}
	friend comp operator * (comp const &x,comp const &y)
	{
		return comp(x.real*y.real-x.imag*y.imag,x.imag*y.real+x.real*y.imag);

	}
	friend comp operator ++ (comp &x)
	{
		x.real=x.real+1;
		x.imag=x.imag+1;
	}
	friend comp operator -- (comp &x)
	{
		x.real=x.real-1;
		x.imag=x.imag-1;
	}
	friend comp operator - (comp const &x)
	{
		return comp(-x.real,-x.imag);
	}
	friend float operator ~ (comp const &x)
	{
		return sqrt(x.real*x.real+x.imag*x.imag);
	}
	void dikhao()
	{
		cout<<real;
		if(imag>=0)
			cout<<"+";
		cout<<imag<<"i\n";
	}


};

int main()
{
	comp a(2,3),b(4,5);
	a.dikhao();
	b.dikhao();
	comp c=a+b;
	c.dikhao();
	c=a-b;
	c.dikhao();
	c=a*b;
	c.dikhao();
	++c;
	c.dikhao();
	--c;
	c.dikhao();
	c=-c;
	c.dikhao();
	cout<<"Mod : "<<~c<<"\n";


}

