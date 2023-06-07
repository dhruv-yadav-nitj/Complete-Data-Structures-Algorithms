
// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void doSolve(vector<int> &arr, vector<int> &ans, int N, int i, int sum)
    {
        if (i == N)
        {
            ans.push_back(sum);
            return;
        }

        // take
        sum += arr[i];
        doSolve(arr, ans, N, i + 1, sum);

        // not take
        sum -= arr[i];
        doSolve(arr, ans, N, i + 1, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        doSolve(arr, ans, N, 0, 0);
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends