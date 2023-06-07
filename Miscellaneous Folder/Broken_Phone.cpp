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
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
        {
            cout << "NEW PHONE" << endl;
        }
        else if (y > x)
        {
            cout << "REPAIR" << endl;
        }
        else if (x == y)
        {
            cout << "ANY" << endl;
        }
    }

    return 0;
}