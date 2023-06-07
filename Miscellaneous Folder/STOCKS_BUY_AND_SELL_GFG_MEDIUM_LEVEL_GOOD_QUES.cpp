
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// User function template for C++

class Solution
{
public:
    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        vector<vector<int>> ans;
        int b(0), s(0);
        bool buy = true; // buy=true means buy is allowed at current moment
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] < A[i + 1] and buy == true)
            {
                buy = false;
                b = i;
            }
            else if (buy == false and A[i] > A[i + 1])
            {
                s = i;
                ans.push_back({b, s});
                buy = true;
            }
        }
        // If we have to sell the last element
        if (buy == false)
        {
            ans.push_back({b, n - 1});
        }
        return ans;
    }
};
//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for (int i = 0; i < ans.size(); i++)
        c += A[ans[i][1]] - A[ans[i][0]];
    return (c == p) ? 1 : 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.stockBuySell(A, n);
        int p = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x = A[i + 1] - A[i];
            if (x > 0)
                p += x;
        }
        if (ans.size() == 0)
            cout << "No Profit";
        else
        {
            cout << check(ans, A, p);
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends