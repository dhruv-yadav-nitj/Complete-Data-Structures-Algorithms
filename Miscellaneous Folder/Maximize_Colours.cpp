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
        vi v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());

        if (v[0] == 0 and v[1] == 0 and v[2] == 0)
            cout << 0 << endl;
        else if (v[0] == 0 and v[1] == 0 and v[2] != 0)
            cout << 1 << endl;
        else if (v[0] == 0 and v[1] == 1 and v[2] == 1)
            cout << 2 << endl;
        else if (v[0] == 0 and v[1] == 1 and v[2] > 1)
            cout << 2 << endl;
        else if (v[0] == 0 and v[1] > 1 and v[2] > 1)
            cout << 3 << endl;
        else if (v[0] == 1 and v[1] == 1 and v[2] == 1)
            cout << 3 << endl;
        else if (v[0] == 1 and v[1] == 1 and v[2] > 1)
            cout << 3 << endl;
        else if (v[0] == 1 and v[1] > 1 and v[2] > 1)
            cout << 4 << endl;
        else if (v[0] == 2 and v[1] == 2 and v[2] == 2)
            cout << 4 << endl;
        else if (v[0] == 2 and v[1] == 2 and v[2] > 2)
            cout << 5 << endl;
        else if (v[0] == 2 and v[1] > 2 and v[2] > 2)
            cout << 5 << endl;
        else if (v[0] > 2 and v[1] > 2 and v[2] > 2)
            cout << 6 << endl;
    }

    return 0;
}