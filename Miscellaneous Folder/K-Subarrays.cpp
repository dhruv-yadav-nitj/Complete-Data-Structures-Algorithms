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

// https://www.codechef.com/submit/KSUB?tab=statement
// Note: A subarray is a contiguous part of array. An array that is inside another array. For example, consider the array [1, 2, 3, 4], There are 10 non-empty sub-arrays. The subarrays are (1), (2), (3), (4), (1,2), (2,3), (3,4), (1,2,3), (2,3,4) and (1,2,3,4).

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi v(n);
        int g(0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            g = __gcd(g, v[i]);
        }
        int count(0), temp(0);
        // since the demand of the equation is non intersecting subarrays. So, let assume {1, 2, 3} it may have subarray such that {1, 2} and {2, 3} or {1, 2, 3} but these subarrays are intersecting somewhere bcz they have some common element. Now assume {1, 2, 3, 4, 5} then the non intersecting subarrays would be like {1, 2, 3} and {4, 5} or {1, 2} and {3, 4, 5}, etc.
        for (int i = 0; i < n; i++)
        {
            temp = __gcd(temp, v[i]);
            if (temp == g)
            {
                temp = 0;
                count++;
            }
        }
        if (count >= k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}