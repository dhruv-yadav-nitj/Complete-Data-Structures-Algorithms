
// arrays are binary
// https://practice.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n)
    {
        // method 1: Naive Solution
        /* int maxi(0);
        for (int i = 0; i < n; i++)
        {
            int sum1(0), sum2(0);
            for (int j = i; j < n; j++)
            {
                sum1 += arr1[j];
                sum2 += arr2[j];
                if (sum1 == sum2)
                {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi; */

        // method 2: Efficient Solution
        // this problem is going to get reduced to the previously done problem of finding the longest subarray with sum = 0;
        // Hint: Subtract the array1-array2
        int temp[n];
        for (int i = 0; i < n; i++)
        {
            temp[i] = arr1[i] - arr2[i];
        }
        int preSum(0), maxi(0);
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            preSum += temp[i];
            if (preSum == 0)
            {
                maxi = max(maxi, i + 1);
            }
            if (m.count(preSum - 0))
            {
                maxi = max(maxi, i - m[preSum - 0]);
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        bool arr1[n], arr2[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.longestCommonSum(arr1, arr2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends