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
    unordered_map<int, int> m;
    int sum(0);
    int maxi(INT_MIN);
    int minus(0);
    for (int i = 0; i < 5; i++)
    {
        int a;
        cin >> a;
        m[a]++;
        sum += a;
        if (m[a] >= 2 and m[a] <= 3)
        {
            minus = max(minus, a * m[a]);
        }
    }
    cout << sum - minus << endl;
    return 0;
}