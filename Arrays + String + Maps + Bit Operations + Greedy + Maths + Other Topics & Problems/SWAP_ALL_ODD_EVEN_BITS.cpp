
// https://youtu.be/GbH8PcqKosk

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
        // used bit masking
        int om = 0x55555555, em = 0xAAAAAAAA;
        int odds = (n & om), evens = (n & em);
        odds <<= 1;
        evens >>= 1;
        n = (odds | evens);
        return n;
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
        unsigned int n;
        cin >> n; // input n

        Solution ob;
        // calling swapBits() method
        cout << ob.swapBits(n) << endl;
    }
    return 0;
}
// } Driver Code Ends