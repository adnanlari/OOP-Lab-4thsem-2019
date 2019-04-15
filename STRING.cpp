#include <bits/stdc++.h>
using namespace std;

class STRING
{
public:
	string s;
	int len;
	STRING(string x="")
	{
		s=x;
		len=x.length();
	}
	friend STRING operator +(STRING const &s1,STRING const &s2)
	{
		STRING s3;
		s3.s=s1.s+s2.s;
		s3.len=s1.len+s2.len;

		return s3;
	}
	friend bool operator ==(STRING const &s1,STRING const &s2)
	{
		return (s1.s).compare((s2.s));
	}
	friend STRING operator /(STRING const &s1,int l)
	{
		STRING s3;
		s3.s=(s1.s).substr(0,l);
		s3.len=l;
		return s3;
	}
	void dikha()
	{
		cout<<"'"<<s<<"'"<<"-->("<<len<<")\n";
	}
};

int main()
{
	STRING s1("Adnan"),s2("Masroor"),s4("Adnan");
	STRING s3=s1+s2;
	s3.dikha();
	if(s1==s4)
		cout<<"NO\n";
	else
		cout<<"YES\n";
	if(s1==s2)
		cout<<"NO\n";
	else
		cout<<"YES\n";
	s3=s2/3;
	s3.dikha();



}