/*******************************************
* AUTHOR : Adnan Masroor
* NICK : adnanlari
* COLLEGE : NIT Durgapur
********************************************/

#include <bits/stdc++.h>
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

    double a=3.14159/20;
	for(ll i=0;i<=10;i++)
	{
		cout<<setw(21)<<setfill(' ')<<"|";
		ll x=(ll)(sin(i*a)*20);
		cout<<setw(x+1)<<setfill('*')<<"\n";
	}
	for(ll i=9;i>=0;i--)
	{
		cout<<setw(21)<<setfill(' ')<<"|";
		ll x=(ll)(sin(i*a)*20);
		cout<<setw(x+1)<<setfill('*')<<"\n";
	}
	for(ll i=1;i<=10;i++)
	{
		ll x=(ll)(sin(i*a)*20);
		cout<<setw(20-x+1)<<setfill(' ')<<"*";
		cout<<setw(x+1)<<setfill('*')<<"|\n";

	}
	for(ll i=9;i>=0;i--)
	{
		ll x=(ll)(sin(i*a)*20);
		cout<<setw(20-x+1)<<setfill(' ')<<"*";
		cout<<setw(x+1)<<setfill('*')<<"|\n";

	}



	return 0;
}