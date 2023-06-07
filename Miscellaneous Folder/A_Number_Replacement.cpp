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
    vi v(n);
    map<int, char> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    string s;
    cin >> s;
    // since it is given in the question that the length of the array and the string are same so its not a matter of concern
    for (int i = 0; i < n; i++)
    {
        m[v[i]] = s[i];
    }
    bool flag(true);
    for (int i = 0; i < n; i++)
    {
        if (m[v[i]] != s[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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