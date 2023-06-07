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
    vl v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n == k)
    {
        l sum(0);
        for (int i = 0; i < k; i++)
        {
            sum += v[i];
        }
        cout << sum << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j += k)
            {
                if (v[j] > v[i])
                {
                    swap(v[i], v[j]);
                }
            }
        }
        l sum(0);
        for (int i = 0; i < k; i++)
        {
            sum += v[i];
        }
        cout << sum << endl;
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