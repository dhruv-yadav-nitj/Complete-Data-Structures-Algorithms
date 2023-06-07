//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int rooms(int N, int M)
    {
        int temp = __gcd(N, M);
        return (N / temp + M / temp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;

        Solution ob;
        cout << ob.rooms(N, M) << "\n";
    }
    return 0;
}
// } Driver Code Ends