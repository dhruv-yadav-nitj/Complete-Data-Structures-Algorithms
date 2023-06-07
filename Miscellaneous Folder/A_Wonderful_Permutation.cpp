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
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    if (n == k)
    {
        cout << 0 << endl;
    }
    else
    {
        int count(0);
        for (int i = 0; i < k; i++)
        {
            if (v[i] > k)
            {
                count++;
            }
        }
        cout << count << endl;
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