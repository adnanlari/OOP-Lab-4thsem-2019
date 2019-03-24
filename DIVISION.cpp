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
        freopen("input.txt", "r", stdin);
        #endif
        
	//the main code starts here

    string a,b;
    cin>>a>>b;
    int la=a.length(),lb=b.length();
    int X[la],Y[lb];
    for(int i=0;i<la;i++)
    	X[i]=(int)a[i]-48;
    for(int i=0;i<lb;i++)
    	Y[i]=(int)b[i]-48;
    

    
	



	return 0;
}