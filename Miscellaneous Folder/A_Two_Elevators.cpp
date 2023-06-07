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
        int a, b, c;
        cin >> a >> b >> c;
        int temp1 = abs(a - 1);
        int temp2 = abs(c - b) + abs(c - 1);
        if (temp1 == temp2)
        {
            cout << 3 << endl;
        }
        else if (temp1 < temp2)
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