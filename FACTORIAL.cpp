/*******************************************
* AUTHOR : Adnan Masroor :-)
* NICK : adnanlari
* COLLEGE : NIT Durgapur
********************************************/

#include<iostream> 
using namespace std; 
#define MAX 1000000
int multiply(int x, int X[], int X_size) 
{ 
    int carry = 0; 
    for (int i=0; i<X_size; i++) 
    { 
        int prod = X[i] * x + carry; 
        X[i] = prod % 10;  
        carry  = prod/10;     
    } 
    while (carry) 
    { 
        X[X_size] = carry%10; 
        carry = carry/10; 
        X_size++; 
    } 
    return X_size; 
} 
void factorial(int n) 
{ 
    int X[MAX];  
    X[0] = 1; 
    int X_size = 1; 
    for (int x=2; x<=n; x++) 
        X_size = multiply(x, X, X_size); 
 
    for (int i=X_size-1; i>=0; i--) 
        cout << X[i]; 
} 

  
// Driver program 
int main() 
{ 
	/*First of all let's clear somethings; Factorial of large numbers can surely be calculated but it will take a lot of time
	* for 30000 its takes more than 10 seconds to compute the factorial.
	* For 100000 it may take more than a half hours.
	*Hence for obvious reasons I have kept input constraint.
	*/
    cout<<"Enter a Number (between 1 to 30000) : ";
    int n;
    cin>>n;
    #ifndef ONLINE_JUDGE
        //freopen("inputfile.txt", "r", stdin);
        freopen("outputfileforfact.txt","w",stdout);
        #endif

        factorial(n);
    return 0; 
} 