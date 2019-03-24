#include <bits/stdc++.h>
using namespace std;

class pol
{
public:
	int *A;
	pol()
	{
		A=new int[100];
		for(int i=0;i<100;i++)
			*(A+i)=0;
		cout<<"Input the power and coefficient (-1 to terminate)\n";
		int x,y;
		while(1)
		{
			cin>>x>>y;
			if(x==-1 || y==-1)
				break;
			A[x]+=y;
		}

	}
	int val(int x)
	{
		int sum=0;
		for(int i=0;i<100;i++)
			sum+=A[i]*pow(x,i);
		return sum;
	}
}