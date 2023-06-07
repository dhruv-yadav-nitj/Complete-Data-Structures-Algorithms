
// https://www.youtube.com/watch?v=s5wC7RrxDzE

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function for finding maximum AND value.
    int doCheckBits(int pattern, int arr[], int n)
    {
        int count(0);
        for (int i = 0; i < n; i++)
        {
            if ((pattern & arr[i]) == pattern)
            {
                count++;
            }
        }
        return count;
    }
    int maxAND(int arr[], int N)
    {
        int ans(0), count(0);
        // since N <= pow(10, 5) and 100000 in binary has 17 bits so loop would run 17 times
        for (int i = 16; i >= 0; i--)
        {
            count = doCheckBits(ans | (1 << i), arr, N);
            if (count >= 2)
            {
                ans = ans | (1 << i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver function
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        int arr[n + 5], i;

        // inserting elements
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        // calling maxAND() function
        cout << obj.maxAND(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends