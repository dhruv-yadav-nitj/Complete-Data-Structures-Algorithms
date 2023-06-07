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
    vl v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    l count(0);
    for (l i = 0; i < n; i++)
    {
        for (l j = i + 1; j < n; j++)
        {
            if (v[j] < v[i])
            {
                count++;
            }
        }
    }
    cout << count << endl;
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