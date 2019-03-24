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
		cout<<imag<<"i";
	}


};

class mat
{
public:
	int size;
	comp **A;
	mat(int s=0)
	{
		size=s;
		A=new comp* [size];
		for(int i=0;i<size;i++)
			*(A+i)=new comp[size];
		cout<<"Input "<<size<<"*"<<size<<" complex elements : \n";
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				int x,y;
				cout<<"Real : ";
				cin>>x;
				cout<<"Imaginary : ";
				cin>>y;
				comp c(x,y);
				(*(*(A+j)+i))=c;
			}
		}
	}
	mat(mat const &x)
	{
		size=x.size;
		A=new comp* [size];
		for(int i=0;i<size;i++)
			*(A+i)=new comp[size];
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
				comp x;
				for(int k=0;k<c.size;k++)
					x=x+(*(*(a.A+k)+i))*(*(*(b.A+j)+k));
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
				*(*(c.A+i)+j)=(*(*(a.A+j)+i));
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
			{
				(*(*(A+j)+i)).dikhao();
				cout<<" ";
			}
			cout<<"\n";
		}

	}
};
int main()
{
	mat a(2),b(2);
	mat c=a+b;
	a.dikha();
	cout<<"\n\n";
	b.dikha();
	cout<<"\n\n";
	c.dikha();
	cout<<"\n\n";
	c=a-b;
	c.dikha();
	cout<<"\n\n";
	c=a*b;
	c.dikha();
	cout<<"\n\n";
	++c;
	c.dikha();
	cout<<"\n\n";
	--c;
	c.dikha();
	cout<<"\n\n";
	c=-c;
	c.dikha();
	cout<<"\n\n";
	c=~c;
	c.dikha();
	cout<<"\n\n";


}
