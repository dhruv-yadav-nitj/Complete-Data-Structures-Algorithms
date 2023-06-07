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
    int n, x, y;
    cin >> n >> x >> y;
    if ((y % x == 0) and y <= n * x)
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