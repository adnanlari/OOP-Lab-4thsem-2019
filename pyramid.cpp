/*******************************************
* AUTHOR : Adnan Masroor
* NICK : adnanlari
* COLLEGE : NIT Durgapur
********************************************/

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair
ll MOD=1000000007,BMOD=100000000700000;

int main()
{
	IOS
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;

    for(ll i=1;i<=n;i++)
    {
    	cout<<setw(n-i+1)<<setfill('*')<<"1";
    	for(ll j=2;j<=i;j++)
    		cout<<j;
    	for(ll k=i-1;k>=1;k--)
    		cout<<k;
    	cout<<"\n";
    }

    
	



	return 0;
}