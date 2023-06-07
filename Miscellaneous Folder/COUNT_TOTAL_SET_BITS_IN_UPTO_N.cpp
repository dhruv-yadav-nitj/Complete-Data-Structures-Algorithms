//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int solve(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        int k = floor(log2(n));
        return k * pow(2, k - 1) + (n - pow(2, k) + 1) + solve(n - pow(2, k));
    }
    int countSetBits(int n)
    {
        // first place
        return solve(n);
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}

// } Driver Code Ends