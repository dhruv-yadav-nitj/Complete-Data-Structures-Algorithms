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
    int n, m, k;
    cin >> n >> m >> k;
    if (m == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        if (n / k >= m)
        {
            cout << m << endl;
        }
        else
        {
            int maxi = n / k;
            // cout << maxi<< endl;
            int leftJoker = m - maxi;
            int leftppl = k - 1;
            int maxinew = ceil((float)leftJoker / leftppl);
            cout << maxi - maxinew << endl;
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