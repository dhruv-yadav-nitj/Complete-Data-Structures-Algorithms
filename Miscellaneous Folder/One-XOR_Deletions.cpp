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
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;
    }
    int temp = n;
    for (auto &&i : m)
    {
        int curr(0);
        if (i.first & 1)
        {
            curr = i.first - 1;
        }
        else
        {
            curr = i.first + 1;
        }
        int ans = i.second;
        auto it = m.find(curr);
        if (it != m.end())
        {
            ans += m[curr];
        }
        if (n - ans < temp)
        {
            temp = n - ans;
        }
    }
    cout << temp << endl;
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