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
    int count(0);
    int a(0);
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a <= 0)
        {
            if (a == 0)
            {
                count = 0;
                flag == false;
            }
            else
            {
                count++;
            }
        }
    }
    if (flag == false)
    {
        cout << 0 << endl;
    }

    if ((count & 1) == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
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