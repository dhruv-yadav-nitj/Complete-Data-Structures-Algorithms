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
    int max(0), ans;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a >= max)
        {
            max = a;
            ans = i;
        }
    }
    cout << ans << endl ;
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