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
    int n, temp(0);
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; i++)
    {
        temp += s[i] != s[i - 1];
    }
    cout << (temp + (s[0] == 49)) / 2 << endl;
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