#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low(0), high(nums.size() - 1), mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return true;
            }

            // whole logic is same as that used in I part of this type of question, only this is different that there were no duplicates theres, but here duplicates may come. so when we encounter duplicates just change low and high
            if (nums[low] == nums[mid] and nums[high] == nums[mid])
            {
                low++, high--;
            }
            else if (nums[mid] >= nums[low])
            {
                if (target >= nums[low] and target < nums[mid])
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (target <= nums[high] and target > nums[mid])
                {
                    low = mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};