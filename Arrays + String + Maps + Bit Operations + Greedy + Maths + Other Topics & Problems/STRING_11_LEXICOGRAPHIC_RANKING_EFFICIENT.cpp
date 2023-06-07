//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    long long factorial(long long n)
    {
        return (n <= 1) ? (1) : (n * (n - 1));
    }
    long long findRank(string str)
    {
        // rather than counting everytime the smaller letter to the right we can store that stuffs earlier in some array

        // us time smjh nhi aaya tha utna so ab pdh le bosdk
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout << ans << endl;
    }
}
// } Driver Code Ends