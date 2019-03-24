/*******************************************************
* Name :Adnan Masroor
* Roll : 17CS8053
* Addition and subtraction of two CoM numbers (using classes and objects)
******************************************************/

#include <bits/stdc++.h>
using namespace std;

class CoM
{
public:
	int r,i;
	CoM()
	{
		r=i=0;
	}
	CoM(int x,int y)
	{
		r=x;
		i=y;
	}
	void display();

};

void CoM::display()
{
	cout<<r;
	if(i>=0)
		cout<<"+";
	cout<<i<<"i\n";
}

void add(CoM a,CoM b)
{
	cout<<"Addition :\n";
	CoM c;
	c.r=a.r+b.r;
	c.i=a.i+b.i;
	c.display();
}

void subtract(CoM a, CoM b)
{
	cout<<"Subtraction :\n";
	CoM c;
	c.r=a.r-b.r;
	c.i=a.i-b.i;
	c.display();

}

int main()
{
	cout<<"Input the CoM numbers : \n";
	int a,b;
	cout<<"First :\n";
	cout<<"Real=";
	cin>>a;
	cout<<"Imaginary=";
	cin>>b;
	CoM c1(a,b);
	cout<<"Second :\n";
	cout<<"Real=";
	cin>>a;
	cout<<"Imaginary=";
	cin>>b;
	CoM c2(a,b);
	c1.display();
	c2.display();
	add(c1,c2);
	subtract(c1,c2);
	return 0;

}