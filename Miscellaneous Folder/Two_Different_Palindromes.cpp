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
    int a, b;
    cin >> a >> b;
    if ((a & 1 == 1) and (b & 1) == 1)
    {
        cout << "NO" << endl;
    }
    else if ((a == 1) or (b == 1))
    {
        cout << "NO" << endl;
    }

    else
    {
        cout << "YES" << endl;
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