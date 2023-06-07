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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int a(-1), b(-1);
    bool temp = true;
    for (int i = 0; i < n and temp == true; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'R')
            {
                a = i, b = j;
                temp = false;
                break ;
            }
        }
    }
    bool flag = true;
    for (int i = a + 1; i < n and flag == true; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'R' and j < b)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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