#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int low = 0, high = x, ans = 1;
        long long mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            else if (mid * mid > x)
            {
                high = mid - 1;
            }
            else if (mid * mid < x)
            {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};