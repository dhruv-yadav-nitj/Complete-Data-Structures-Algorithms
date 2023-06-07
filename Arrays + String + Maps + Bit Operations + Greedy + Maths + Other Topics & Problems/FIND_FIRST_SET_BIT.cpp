//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        int pos(1);
        for (int i = 1; i <= 32; i++, pos++)
        {
            if ((n & (1 << (i - 1))) != 0)
            {
                return pos;
            }
        }
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
    return 0;
}

// } Driver Code Ends