// Find square root of number in integer. For Ex. 9 has 3 as sq root and 10 also has 3 has square root
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

int sqroot(int n)
{
    // time complexity: O(logn)
    int s(0), e(n);
    int mid, ans(0);
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
            ans = mid;
        }
    }return ans ;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    cout << sqroot(n) << endl ;

    return 0;
}