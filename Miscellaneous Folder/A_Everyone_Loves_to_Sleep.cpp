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
    int n, sh, sm;
    cin >> n >> sh >> sm;
    int timeZero = sh * 60 + sm;
    vi v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(a * 60 + b);
    }
    sort(v.begin(), v.end());
    if (v[n - 1] < timeZero)
    {
        int ans = v[0] + (1440 - timeZero);
        cout << ans / 60 << " " << ans % 60 << endl;
    }
    else
    {
        int ans;
        for (int i = 0; i < n; i++)
        {
            ans = v[i] - timeZero;
            if (ans >= 0)
            {
                cout << ans / 60 << " " << ans % 60 << endl;
                break;
            }
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