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
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans(INT_MAX);
    for (int i = 0; i < n - 2; i++)
    {
        if (v[i] == v[i + 1] and v[i] == v[i + 2])
        {
            ans = min(ans, 0);
            break;
        }
        else if (v[i] == v[i + 1] or v[i + 1] == v[i + 2])
        {
            if (v[i] == v[i + 1])
            {
                ans = min(ans, v[i + 2] - v[i + 1]);
            }
            else
            {
                ans = min(ans, v[i + 1] - v[i]);
            }
        }
        else
        {
            ans = min(ans, (v[i + 2] - v[i + 1] + v[i + 1] - v[i]));
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