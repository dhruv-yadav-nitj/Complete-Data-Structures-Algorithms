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
    sort(v.begin(), v.end());
    bool flag(true);
    int temp = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] % temp > 0)
        {
            cout << n << endl;
            return;
        }
    }
    int count(0);
    for (int i = 0; i < n; i++)
    {
        if (v[i] == temp)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    cout << n - count << endl;
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