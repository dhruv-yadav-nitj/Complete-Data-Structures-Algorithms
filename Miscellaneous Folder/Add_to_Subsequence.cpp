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
    l n;
    cin >> n;
    bool flag = true;
    vl v(n);
    map<l, l> m;
    // set<int> s;
    l maxi(INT_MIN);
    for (l i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;
        maxi = max(maxi, m[v[i]]);
        if (m[v[i]] > 1)
        {
            flag = false;
        }
        // s.insert(v[i]);
    }
    if (flag == true)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ceil(log2(maxi)) << endl ;
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