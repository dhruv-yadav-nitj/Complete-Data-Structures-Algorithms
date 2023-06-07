
// Same problem on LeetCode #525

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution
{
public:
    int maxLen(int arr[], int N)
    {
        // Method 1: Naive Solution
        /* int maxi(0);
        for (int i = 0; i < N; i++)
        {
            int countZ(0), countO(1);
            for (int j = i; j < N; j++)
            {
                if (arr[j] == 0)
                {
                    countZ++;
                }
                if (arr[j] == 1)
                {
                    countO++;
                }
                if (countZ == countO)
                {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi; */

        // method 2: Efficient Approach
        // Hint: This problem is going to reduce into the problem of finding length of longest subarray with 0 sum. Replace all the 0 with -1;
        int preSum(0), maxi(0);
        unordered_map<int, int> m;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] == 1)
            {
                preSum += 1;
            }
            else
            {
                preSum -= 1;
            }

            if (preSum == 0)
            {
                maxi = max(maxi, i + 1);
            }
            if (m.count(preSum))
            {
                maxi = max(maxi, i - m[preSum]);
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
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends