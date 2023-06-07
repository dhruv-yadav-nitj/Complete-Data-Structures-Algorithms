//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:

    // required time complexity : O(N) and aux space : O(1) 

    // approach : ques mein negative numbers bhi de skta hain
    // consider two examples : {1, 2, 3, 5} and {-3, -5, 1, 0, 8, 3, -2}
    // in first example we can simply take product of the three largest numbers
    // in second exmaple --> we have to multiply the two negative numbers and then a positive largest number to get the ans --> so isase hme pata chala ki ans ya to skta hain ki three largest numbers wo honge ya two smallest negative numbers (jo ki jb modulus lenge in numbers ka then positive milega and saath mein largest number) to inhi dono mein se max ans hoga

    long long maxTripletProduct(long long arr[], int n)
    {
    	long long big1 = INT_MIN , big2 = INT_MIN , big3 = INT_MIN ;
    	long long smal1 = INT_MAX, smal2 = INT_MAX ;
    	for(int i = 0 ; i <  n ; i++){
    	    if(arr[i] > big1){
    	        big3 = big2 ; big2 = big1 ; big1 = arr[i] ;
    	    }
    	    else if(arr[i] > big2){
    	        
    	        big3 = big2 ; big2 = arr[i] ;
    	        
    	    }
    	    else if(arr[i] > big3){
    	        big3 = arr[i] ;
    	    }
    	    
    	    
    	    if(arr[i] < smal1){
    	        smal2= smal1 ; smal1 = arr[i] ;
    	    }
    	    else if(arr[i] < smal2){
    	        smal2 = arr[i] ;
    	    }
    	}
    	
    	
    	return max(big1 * big2 * big3 , big1 * smal1 * smal2) ;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends