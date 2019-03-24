/*******************************************
* AUTHOR : Adnan Masroor :-)
* NICK : adnanlari
* COLLEGE : NIT Durgapur
********************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
        freopen("inputfile.txt", "r", stdin);
        freopen("outputfile.txt", "w", stdout);
        #endif
	
	//the main code starts here

	string a,b;
	cin>>a>>b;
	int la=a.length(),lb=b.length(),f=0;
	if(la<lb)
		f=1;
	else if(la==lb)
	{
		for(int i=0;i<la;i++)
		{
			if(a[i]<b[i])
			{
				f=1;
				break;
			}
			else if(a[i]>b[i])
			{
				f=0;
				break;
			}
		}

	}
	if(f)
	{
		string x=a;
		a=b;
		b=x;
	}
	la=a.length();
	lb=b.length();
	for(int i=1;i<=(la-lb);i++ )
		b="0"+b;
	int ans[la];
	for(int i=la-1;i>=0;i--)
	{
		ans[i]=a[i]-b[i];
		if(ans[i]<0)
		{
			ans[i]+=10;
			int j=i-1;
			while(1)
			{
				--a[j];
				if(a[j]!='/')
					break;
				else
				{
					a[j]='9';
					j--;
				}
			}
		}	
	}
	int d=0;
	for(d=0;d<la;d++)
	{
		if(ans[d]!=0)
			break;
	}
	if(f)
		cout<<"-";
	if(d==la)
		cout<<"0";
	else
	{
		for(int i=d;i<la;i++)
			cout<<ans[i];
	}
	cout<<"\n";
    
	



	return 0;
}