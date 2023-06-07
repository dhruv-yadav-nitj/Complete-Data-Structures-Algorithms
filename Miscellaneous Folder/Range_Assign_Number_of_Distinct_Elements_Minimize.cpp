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
    if (n <= 2)
    {
        cout << "YES" << endl;
    }
    else if (v[0] == v[n - 1] or v[0] == v[n - 2] or v[1] == v[n - 1])
    {
        cout << "YES" << endl;
    }
    else
    {
        bool flag = true;
        int a = v[0];
        for (int i = 1; i <= n - 3; i++)
        {
            if (v[i] == a)
            {
                if (v[i + 1] == v[n - 1])
                {
                    cout << "YES" << endl;
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "NO" << endl;
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