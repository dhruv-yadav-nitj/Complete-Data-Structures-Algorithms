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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // Time Complexity: O(n^3)
    // printing all the subarrays using iteration
    // choosing starting point
    for (int i = 0; i < n; i++)
    {
        // choosing end point
        for (int j = i; j < n; j++)
        {
            // printing all the subarrays
            for (int k = i; k <= j; k++)
            {
                cout << v[k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}