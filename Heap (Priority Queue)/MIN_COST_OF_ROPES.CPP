//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        // Your code here
        long long ans = 0 ;
        
        // for min cost --> choose two smallest ropes --> bs yhi krna hain hr ek step mein
        // use priority que --> min heap --> to get the two smallest element at every step

        priority_queue<long long, vector<long long>, greater<long long>> pq ;
        for(long long i =0 ;i  < n ; i++){
            pq.push(arr[i]) ;
        }

        while(n > 1){
            long long temp = ans ;
            ans += pq.top() ; pq.pop() ; ans += pq.top() ; pq.pop() ;
            pq.push(ans - temp) ; n-- ;
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends