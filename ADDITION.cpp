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
	//since the numbers are too large they are taken as strings which can take as many as 10^7 digits!
	int la=a.length(),lb=b.length(),carry=0;
	if(la>lb)
	{
		for(int i=1;i<=(la-lb);i++)
			b="0"+b;
	}
	else if(lb>la)
	{
		for(int i=1;i<=(lb-la);i++)
			a="0"+a;
	}
	la=a.length();
	int ans[la+1];
	for(int i=0;i<=la;i++)
		ans[i]=0;
	//cout<<a<<" "<<b<<"\n";
	for(int i=la-1;i>=0;i--)
	{
		int x=(int)a[i]-48,y=(int)b[i]-48;
		x+=y+carry;
		ans[i+1]=x%10;
		carry=x/10;
	}
	ans[0]=carry;
	int i=0;
	if(ans[0]==0)
		i=1;
	while(i<=la)
	{
		cout<<ans[i];
		i++;
	}
	cout<<"\n";

    
	



	return 0;
}