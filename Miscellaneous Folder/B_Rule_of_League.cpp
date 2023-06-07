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
    int each = max(x, y);
    if ((x > 0 and y > 0) or (x == 0 and y == 0) or (x >= n or y >= n))
    {
        cout << -1 << endl;
    }
    else
    {
        if (each == 1)
        {
            for (int i = 2; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else if (n % each == 1)
        {
            int winner = 1;
            for (int i = 1; i <= n - 1; i++)
            {
                cout << winner << " ";
                if (i % each == 0)
                {
                    winner = i + 2;
                }
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
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