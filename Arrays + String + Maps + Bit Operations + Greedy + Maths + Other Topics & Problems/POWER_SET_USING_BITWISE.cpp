#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

/*
If we have n elements in a set then the Power Set would have pow(2, n) elements.
*/

vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    int n = s.length();
    int powersetSize = pow(2, n);
    for (int i = 0; i < powersetSize; i++)
    {
        string temp = "";
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                temp += s[j];
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    IOS;
    string s;
    cin >> s;
    vector<string> ans = AllPossibleStrings(s);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}