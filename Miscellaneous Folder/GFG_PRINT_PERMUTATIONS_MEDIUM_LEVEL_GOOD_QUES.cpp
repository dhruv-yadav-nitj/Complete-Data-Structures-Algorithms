
// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
// Problem Statement: Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.
// Also no duplicates are allowed.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void doSolve(string S, vector<string> &ans, int index)
    {
        if (index == S.length())
        {
            ans.push_back(S);
            return;
        }
        for (int i = index; i < S.length(); i++)
        {
            swap(S[index], S[i]);
            doSolve(S, ans, index + 1);
            swap(S[index], S[i]);
        }
    }
    vector<string> find_permutation(string S)
    {
        vector<string> ans;
        doSolve(S, ans, 0);
        sort(ans.begin(), ans.end());

        //  since duplicates are not allowed we have to use sets
        set<string> s;
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
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends