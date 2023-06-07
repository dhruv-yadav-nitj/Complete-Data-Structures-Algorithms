
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
/*
Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits.
*/
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define vp vector<vector<int>>
using namespace std;

bool custom(vi &a, vi &b)
{
    return a[0] < b[0];
}

int main()
{
    vp v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), custom);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int platNeeded = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (v[i][1] > v[j][0])
            {
                platNeeded++;
            }
        }
        ans = max(platNeeded, ans);
    }
    cout << ans << endl;
    return 0;
}
