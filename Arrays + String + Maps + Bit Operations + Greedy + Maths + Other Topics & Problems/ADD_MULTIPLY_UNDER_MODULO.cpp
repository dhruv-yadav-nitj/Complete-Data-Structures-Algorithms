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
    l temp1 = a % (1000000007), temp2 = b % (1000000007);
    cout << temp1 << " " << temp2 << endl;
    cout << (temp1 + temp2) % (1000000007) << endl;
    cout << (temp1 * temp2) % (1000000007) << endl;

    return 0;
}