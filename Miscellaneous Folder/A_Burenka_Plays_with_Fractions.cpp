#include <bits/stdc++.h>
#define l unsigned long long
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
    int t;
    cin >> t;
    while (t--)
    {
        l a, b, c, d;
        cin >> a >> b >> c >> d;
        l x = a * d, y = b * c;
        // cout << x << " " << y << endl ;
        if (x == y)
        {
            cout << 0 << endl;
        }
        else if ((x != 0 and y % x == 0) or (y != 0 and x % y == 0))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }

    return 0;
}