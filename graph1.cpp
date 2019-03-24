/*******************************************
* AUTHOR : Adnan Masroor :-)
* NICK : adnanlari
* COintEGE : NIT Durgapur
********************************************/

#include <bits/stdc++.h>
using namespace std;


fstream i,o;

//Here the inputs are taken from the file named "input.txt", and the output is displayed on the terminal!
//This program reads the number of nodes and the given edges from the file and displays the connected sub-graphs
// in different lines.


int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);

	i.open("input.txt", ios::in);
	o.open("output.txt", ios::out);
	
	//the main code starts here
	// here 'int' means long long int
	int n;
	i>>n;
	//reading the numbers of node.

	int *visit=new int[n];
	int **X=new int* [n];
	for(int i=0;i<n;i++)
		X[i]=new int[n];
	
	//Adjancy matrix is used to denote the edges.
	while(i)
	{
		int a,b;
		i>>a>>b;
		X[a][b]=1;
		X[b][a]=1;

	}
	for(int ip=0;ip<n;ip++)
	{
		if(!visit[ip])
		{
			//Breadth First Search is used to traverse the graph!
			queue <int> Q;
			Q.push(ip);
			visit[ip]=1;
			while(!Q.empty())
			{
				int x=Q.front();
				Q.pop();
				cout<<x<<" ";
				for(int is=0;is<n;is++)
				{
					if(!visit[is] && X[x][is])
					{
						visit[is]=1;
						Q.push(is);
					}
				}

			}
			o<<"\n";
		}
	}

    
	



	return 0;
}