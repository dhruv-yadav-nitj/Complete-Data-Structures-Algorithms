
// https://www.geeksforgeeks.org/find-square-root-number-upto-given-precision-using-binary-search/
// Find square root of number upto given precision using binary search

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

float sqrtE(int n, int precision)
{
    int s(0), e(n);
    float ans(0);
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid * mid == n)
        {
            ans = mid;
            break;
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
    }
    float currPrecision = 0.1;
    for (int i = 0; i < precision; i++)
    {
        while (ans * ans <= n)
        {
            ans += currPrecision;
        }
        ans = ans - currPrecision;
        currPrecision /= 10;
    }
    return ans;
}

int main()
{
    IOS;
    int n, precision;
    cin >> n >> precision;
    cout << sqrtE(n, precision) << endl;

    return 0;
}