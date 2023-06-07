
// https://practice.geeksforgeeks.org/problems/print-pattern3549/1/?page=1&category[]=pattern-printing&sortBy=submissions#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void temp(int N, vector<int> &v)
    {
        if (N > 0)
        {
            v.push_back(N);
            temp(N - 5, v);
        }
        v.push_back(N);
    }
    vector<int> pattern(int N)
    {
        vector<int> v;
        temp(N, v);

        return v;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        vector<int> ans = ob.pattern(N);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}