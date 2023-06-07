
// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    void doSolve(vector<int> &A, vector<vector<int>> &ans, vector<int> temp, int index, int target)
    {
        if (index == A.size())
        {
            if (target == 0)
            {
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            return;
        }

        // pick
        if (target >= A[index])
        {
            temp.push_back(A[index]);
            doSolve(A, ans, temp, index, target - A[index]);
            temp.pop_back();
        }

        // not pick
        doSolve(A, ans, temp, index + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        doSolve(A, ans, temp, 0, B);
        // sort(ans.begin(), ans.end()) ;
        set<vector<int>> s;
        for (int i = 0; i < ans.size(); i++)
        {
            s.insert(ans[i]);
        }
        ans.clear();
        for (auto x : s)
        {
            ans.push_back(x);
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
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}
// } Driver Code Ends