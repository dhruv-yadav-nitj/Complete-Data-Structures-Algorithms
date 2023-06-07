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
    int n, q;
    cin >> n >> q;
    vi nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int temp(0);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (((a - b + 1) & 1 == 1) or (a == b))
        {
            temp += 1;
        }
    }
    int sum = accumulate(nums.begin(), nums.end(), 0);
    cout << sum + temp << endl;
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