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
    sort(v.begin(), v.end(), greater<int>());
    map<int, int> m;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        while (v[i] > n or m[v[i]] == 1)
        {
            v[i] /= 3;
        }
        if (v[i] > 0)
        {
            m[v[i]]++;
        }
        else
        {
            cout << "NO" << endl;
            flag = false;
            break;
        }
    }
    if (flag)
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