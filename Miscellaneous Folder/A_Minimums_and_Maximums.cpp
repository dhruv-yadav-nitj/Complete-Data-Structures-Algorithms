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
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 >= l2 and l1 <= r2)
    {
        cout << l1 << endl;
    }
    else if ((l1 > l2 and l1 > r2) or (l2 > l1 and l2 > r1))
    {
        cout << l1 + l2 << endl;
    }
    else if (l2 >= l1 and l2 <= r1)
    {
        cout << l2 << endl;
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