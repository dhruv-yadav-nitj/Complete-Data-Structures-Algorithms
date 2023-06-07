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

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/solutions/2814630/c-easy-approach-binary-search-well-explained/

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int low(0), high(nums.size() - 1);
        // we would apply binary search two times
        int maxi(-1);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                maxi = max(maxi, mid);
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
        }

        int mini(1000000);
        low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                mini = min(mini, mid);
                high = mid - 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
        }

        if (maxi == -1)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};