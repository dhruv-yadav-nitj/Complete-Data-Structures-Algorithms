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
    l a, b;
    cin >> a >> b;
    l lcm = (a * b) / (__gcd(a, b));
    if (a == b or (lcm / min(a, b) - lcm / max(a, b) == 1))
    {
        cout << "Equal" << endl;
    }
    else if (a > b)
    {
        cout << "Masha" << endl;
    }
    else
    {
        cout << "Dasha" << endl;
    }

    return 0;
}