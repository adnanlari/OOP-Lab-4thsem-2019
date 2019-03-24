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
        freopen("outputfile.txt","w",stdout);
        #endif
	
	//the main code starts here

	string a,b;
	cin>>a>>b;
	int ans[1000001]={0};
	int la=a.length(),lb=b.length(),x=0,y,i,j;
	for(i=lb-1;i>=0;i--)
	{
		vector <int> V;int carry=0;
		for(j=la-1;j>=0;j--)
		{
			int m=((int)b[i]-48)*((int)a[j]-48)+carry;
			V.push_back(m%10);
			carry=m/10;

		}
		V.push_back(carry);
		carry=0;
		for(int j=0;j<V.size();j++)
		{
			int m=ans[x+j]+V[j]+carry;
			ans[x+j]=m%10;
			carry=m/10;
		}
		x++;
	}
	for(i=1000000;i>=0;i--)
	{
		if(ans[i]!=0)
			break;

	}
	if(i!=-1)
	{
		while(i>=0)
			cout<<ans[i--];
	}
	else
		cout<<"0";
	cout<<"\n";


    
	



	return 0;
}