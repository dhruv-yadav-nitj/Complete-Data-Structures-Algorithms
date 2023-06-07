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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> temp;
    temp.push(s[0]);
    for (int i = 1; i < n; i++)
    {
        if (temp.top() == s[i])
        {
            temp.pop();
            temp.push('0');
        }
        else
        {
            temp.push(s[i]);
        }
    }
    if (temp.size() == 1)
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        char ch = temp.top();
        temp.pop();
        while (!temp.empty() and temp.top() == ch)
        {
            temp.pop();
        }
        if (temp.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    IOS;
    l t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}