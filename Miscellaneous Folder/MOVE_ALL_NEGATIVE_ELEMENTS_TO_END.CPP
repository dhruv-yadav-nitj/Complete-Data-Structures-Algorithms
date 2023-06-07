//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1

// } Driver Code Ends
class Solution{
public:
    void segregateElements(int arr[], int n){
        // CODE HERE
        int temp1[n], temp2[n] ; int count1(0), count2(0); 
        for(int i=0; i< n; i++){
            if(arr[i] >= 0){temp2[count2] = arr[i] ; count2++ ;}
            else{
                temp1[count1] = arr[i] ; count1++ ;
            }
        }
        for(int i=  0; i< count2; i++){
            arr[i] = temp2[i] ;
        }
        for(int i=count2 ; i < n ; i++){
            arr[i] = temp1[i-count2] ;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        ob.segregateElements(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}

// } Driver Code Ends