/*******************************************
* AUTHOR : Adnan Masroor :-)
* NICK : adnanlari
* COLLEGE : NIT Durgapur
********************************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
ll MOD=1000000007,BMOD=100000000700000;

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	
	fstream in,out;
	in.open("testfile.cpp",ios::in);
	out.open("intended_testfile.cpp",ios::out);
	//the main code starts here

	if(!in || !out)
	{
		cout<<"File Accessing failed!! Try Again!! \n";
		return 0;
	}
	char ch;
	while(!in.eof())
	{
		in>>ch;
		out<<ch;
	}



	in.close();
	out.close();
	
    	
	



	return 0;
}