/*******************************************
* AUTHOR : Adnan Masroor :-)
* NICK : adnanlari
* COLLEGE : NIT Durgapur
********************************************/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv )
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	fstream f1,f2;
	f1.open(argv[1], ios::in);
	f2.open(argv[2],ios::out);
	//the main code starts here
        string s;
        int count=0;
        while(f1)
        {
        	getline(f1,s);
        	int l=s.length(),i=0;
        	//f2<<count;
        	for(int i=0;i<count;i++)
        		f2<<"\t\t";
        	f2<<s;
        	while(i<l)
        	{
	        	if(s[i]=='{')
	        		count++;
	        	else if(s[i]=='}')
	        		count--;
	        	i++;
        	}
        	if(s[l-1]=='{' || s[l-1]=='}' || s[l-1]==';' || s[l-1]=='/' || s[l-1]==')' || s[l-1]==':')
        		f2<<"\n";

        }
        f1.close();
        f2.close();
    
	



	return 0;
}