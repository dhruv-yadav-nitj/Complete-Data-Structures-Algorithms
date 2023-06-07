
// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        // Complete the function
        int preSum(0), maxi(0), count(0);
        unordered_map<int, int> m;
        for (int i = 0; i < N; i++)
        {
            preSum += A[i];
            if (preSum == K)
            {
                maxi = max(maxi, i + 1);
            }
            if (m.count(preSum - K))
            {
                maxi = max(maxi, i - m[preSum - K]);
            }
            if (m.find(preSum) == m.end())
            {
                m[preSum] = i;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    // code

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;
    }

    return 0;
}
// } Driver Code Ends