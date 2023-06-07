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
    if ((n & 1) == 1)
    {
        cout << 1 << " " << 2 << " " << 3 << " ";
        for (int i = n - 2; i >= 4; i--)
        {
            cout << i << " ";
        }
        cout << n - 1 << " " << n << endl;
    }
    else
    {
        for (int i = n - 2; i >= 1; i--)
        {
            cout << i << " ";
        }
        cout << n - 1 << " " << n << endl;
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