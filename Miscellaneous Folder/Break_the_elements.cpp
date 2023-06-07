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
    int countOdd(0), countEven(0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if ((v[i] & 1) == 1)
        {
            countOdd++;
        }
        else
        {
            countEven++;
        }
    }
    if (countOdd == 0 or countEven == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << countEven << endl;
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