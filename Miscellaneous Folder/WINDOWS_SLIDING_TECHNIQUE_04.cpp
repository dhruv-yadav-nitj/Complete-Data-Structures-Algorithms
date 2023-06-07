
// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
// Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {
        vector<int> ans;
        map<int, int> m;
        int count(0);

        // first consider the first windows of k elements
        for (int i = 0; i < k; i++)
        {
            m[A[i]]++;
            if (m[A[i]] == 1)
            {
                count++;
            }
        }
        ans.push_back(count);

        // then lets go to the second window of k elements
        for (int i = k; i < n; i++)
        {
            m[A[i - k]]--;
            if (m[A[i - k]] == 0)
            {
                count--;
            }
            m[A[i]]++;
            if (m[A[i]] == 1)
            {
                count++;
            }
            ans.push_back(count);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> result = obj.countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends