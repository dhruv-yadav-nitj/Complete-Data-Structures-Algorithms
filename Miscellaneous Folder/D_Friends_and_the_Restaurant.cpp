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
    vi xi(n), yi(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xi[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> yi[i];
    }
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back(yi[i] - xi[i]);
    }
    sort(temp.begin(), temp.end());
    int s(0), e(n - 1), count(0), sum(temp[0]);
    int ans(0);
    while (s < e)
    {
        sum += temp[e];
        if (sum >= 0)
        {
            count++;
            s++;
            sum = temp[s];
            e--;
        }
        else if (sum < 0)
        {
            s++;
            sum = temp[s];
        }
    }
    cout << count << endl;
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