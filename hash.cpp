/******************************************
* Name : Adnan Masroor
* Roll : 17CS8053
* Subject : OOP Laboratory
******************************************/

//All the output will be displayed in a file named "output_for_hash.txt" which will be attached with the code.
//This code will generate a table for values  hashed in the hash table of size 100.
//Values will be added in the batches of 20, 40, 60 and 80.
//values will be generated randomly.
//The table will contain the the value added and the number of miss before its is added.
// At the end of the table total number of miss will be displayed.
// Hash function : h%100

#include <bits/stdc++.h>
using namespace std;
#define MAX 100

fstream o;



int main()
{
	srand(time(0));
	o.open("output_for_hash.txt", ios::out);
	int *M=new int[6];

	for(int num=20;num<=100;num+=20)
	{

		int *A=new int[100];
		
		
		for(int i=0;i<100;i++)
			*(A+i)=-1;
		
		o<<"\nThis Table is for "<<num<<" element chosen randomly.\n";
		
		o<<"VALUES\t\t\tINDEX(initial)\t\t\tINDEX(final)\t\t\tMISSES\n";
		int total_miss=0;

		for(int i=1;i<=num;i++)
		{
			int x=rand();
			//cout<<x<<"\n";
			int miss=0;
			int index=x%100;
			int indi=index;
			while(*(A+index)!=-1)
			{
				miss++;
				index++;
				if(index==100)
					index=0;
			}
			*(A+index)=x;
			o<<x<<"\t\t"<<indi<<"\t\t\t\t"<<index<<"\t\t\t\t"<<miss<<"\n";
		
			

			total_miss+=miss;
		}
		o<<"\n\nTOTAL MISSES : "<<total_miss<<"\n\n";
		M[num/20]=total_miss;
		


		delete A;
	}
	int a=0,b=0;
	
	o<<"THE MAIN TABLE SHOWING THE VARIATION OF MISSES WITH INCREASING NUMBER OF ELEMENTS :\n\nNUMBER OF ELEMENTS\tNUMBER OF MISSES\n";
	for(int i=1;i<=5;i++)
	{
		a+=M[i];
		b+=M[i]*M[i];
		o<<i*20<<"\t\t\t"<<M[i]<<"\n";
	}
	float avg=(float)a/5;
	o<<"AVERAGE MISS : "<<avg<<"\n\n";
	float var=(float)b/5-(avg*avg);
	o<<"VARIANCE OF THE MISSES : "<<var<<"\n";


	return 0;
}

