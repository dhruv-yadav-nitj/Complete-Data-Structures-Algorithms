#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        long long n = nums.size();
        long long left(nums[0]), right(0), mini(INT_MAX), ans(0);
        right = accumulate(nums.begin(), nums.end(), 0l) - nums[0];

        for (long long i = 0; i < nums.size() - 1; i++)
        {
            long long temp = abs(round(left / (i + 1)) - round(right / (n - i - 1)));
            if (temp < mini)
            {
                mini = temp;
                ans = i;
            }
            left = left + nums[i + 1];
            right = right - nums[i + 1];
        }

        long long temp = (round(left / (n)));
        if (temp < mini)
        {
            mini = temp;
            ans = n - 1;
        }

        return ans;
    }
};