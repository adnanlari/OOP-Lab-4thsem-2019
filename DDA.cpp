#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"Enter the dimension : ";
	int n;
	cin>>n;
	int **A=new int*[n];
	for(int i=0;i<n;i++)
		A[i]=new int[n];
	cout<<"Enter the n matrix :\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>*(*(A+i)+j);
	}
	cout<<"Upper Matrix :\n";
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<i;k++)
			cout<<"0 ";
		for(int j=i;j<n;j++)
			cout<<*(*(A+i)+j)<<" ";
		cout<<"\n";
	}
	cout<<"Lower Matrix :\n";
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<=i;k++)
			cout<<*(*(A+i)+k)<<" ";
		for(int j=i+1;j<n;j++)
			cout<<"0 ";
		cout<<"\n";
	}
	cout<<"Sum of the upper ansd lower matrix :\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				cout<<(*(*(A+i)+j))*2<<" ";
			else
				cout<<*(*(A+i)+j)<<" ";
		}
		cout<<"\n";
	}


	return 0;
}
