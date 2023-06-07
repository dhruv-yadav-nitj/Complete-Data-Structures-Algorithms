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
    map<int, int> m;
    set<int> s;
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
        m[a]++;
    }
    int ans(0);
    for (auto x : s)
    {
        if (c <= m[x])
        {
            ans += c;
        }
        else
        {
            ans += m[x];
        }
    }
    cout << ans << endl;
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