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
        l n, m;
        cin >> n >> m;
        l arr[n];
        l sum(0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (abs(arr[i] - 1) > abs(arr[i] - m))
            {
                sum += abs(arr[i] - 1);
            }
            else
            {
                sum += abs(arr[i] - m);
            }
        }
        cout << sum << endl ;
    }

    return 0;
}