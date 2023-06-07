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

int main()
{
    IOS;
    int n;
    cin >> n;
    vi a(n), b(n);
    bool ok[n];
    memset(ok, true, n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int count(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] == b[i] and ok[j] == true and i!=j)
            {
                count++;
                ok[j] = false;
            }
        }
    }
    // cout << count << endl ;
    cout << n - count << endl;

    return 0;
}