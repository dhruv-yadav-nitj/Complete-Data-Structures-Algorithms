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

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        // Method 1: Naive :- Got TLE
        /*
        int i(0);
        while (i < nums.size())
        {
            int sum(nums[i]);
            int j(i + 1);
            while (j < nums.size())
            {
                sum += nums[j];
                if (sum % k == 0)
                {
                    return true;
                }
                j++;
            }
            i++;
        }
        return false;
        */

        // Method 2:- Using Hashing --> Accepted
        unordered_map<int, int> m;
        int preSum(0);
        for (int i = 0; i < nums.size(); i++)
        {
            preSum += nums[i];
            preSum %= k;
            if (preSum == 0 and i >= 1)
            {
                return true;
            }
            if (m.find(preSum) != m.end())
            {
                if ((i - m[preSum]) >= 2)
                {
                    return true;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                m[preSum] = i;
            }
        }
        return false;
    }
};