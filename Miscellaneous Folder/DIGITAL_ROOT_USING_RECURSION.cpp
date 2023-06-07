//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int singleDigit(long long N)
    {
        if (floor(log10(N) + 1) == 1)
        {
            return N;
        }
        int sum(0);
        while (N > 0)
        {
            sum += N % 10;
            N /= 10;
        }
        return singleDigit(sum);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        int ans = ob.singleDigit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends