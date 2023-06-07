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

// https://leetcode.com/problems/contiguous-array/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int maxi(0), preSum(0);
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                preSum += 1;
            }
            else
            {
                preSum -= 1;
            }

            if (preSum == 0)
            {
                maxi = max(maxi, i + 1);
            }
            if (m.count(preSum))
            {
                maxi = max(maxi, i - m[preSum]);
            }
            if (m.find(preSum) == m.end())
            {
                m[preSum] = i;
            }
        }
        return maxi;
    }
};