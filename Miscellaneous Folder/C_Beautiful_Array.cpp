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
    int count(0);
    int ans[10000], temp[10000];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
        if (i > 0)
        {
            if (__gcd(temp[i], temp[i - 1]) != 1)
            {
                ans[j] = 1;
                j++, count++;
            }
        }
        ans[j] = temp[i];
        j++;
    }
    cout << count << endl;
    for (int i = 0; i < j; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}