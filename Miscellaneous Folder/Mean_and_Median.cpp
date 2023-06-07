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
        int temp = (x * 3) - (y);
        // cout << 0 << " " << y << " " << temp << endl;
        int temp1 = (x*3)-(y*2) ;
        cout << min(temp1, y) << " " << y << " " << max(temp1, y) << endl ;
    }

    return 0;
}