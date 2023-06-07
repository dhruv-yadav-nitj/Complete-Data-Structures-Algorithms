#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int i(0), j(nums.size() - 1);
        int store(-1);

        // if target is less than the start element of the nums then we insert the target at 0th index
        if (target < nums[0])
        {
            return 0;
        }

        // if target is greater than the last element of the sorted array then the only option is to insert the element at last
        if (target > nums[nums.size() - 1])
        {
            return nums.size();
        }

        // now search for the target using Binary Search
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target or nums[mid] > target and nums[mid - 1] < target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return -1;
    }
};