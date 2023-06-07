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
    int n;
    cin >> n;
    vi v(n);
    int temp1(INT_MIN), temp2(INT_MIN), temp3(INT_MIN), temp4(INT_MIN);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // corner elements
    temp1 = v[n - 1] - v[0];

    // when all the elements being selected, then the position of the vn and v1 not changed
    for (int i = 0; i < n - 1; i++)
    {
        temp2 = max(temp2, v[i] - v[i + 1]);
    }

    // when v1 not selected but vn selected
    for (int i = 1; i < n; i++)
    {
        temp3 = max(temp3, v[i] - v[0]);
    }

    // when v1 selected and not vn
    for (int i = 0; i < n - 1; i++)
    {
        temp4 = max(temp4, v[n - 1] - v[i]);
    }
    cout << max({temp1, temp2, temp3, temp4}) << endl;
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