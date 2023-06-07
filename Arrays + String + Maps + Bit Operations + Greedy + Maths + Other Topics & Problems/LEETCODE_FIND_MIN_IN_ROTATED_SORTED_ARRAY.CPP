#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int low(0), high(n - 1), mid;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (mid - 1 >= 0 and nums[mid] < nums[mid - 1])
            {
                return nums[mid];
            }
            if (mid + 1 < n and nums[mid] > nums[mid + 1])
            {
                return nums[mid + 1];
            }
            if (nums[mid] < nums[low])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
};

/*
Since the array is rotated, the array is divided into two sorted arrays. So, the minimum element would be either the starting of the first array(nums[0]) or the starting of the other array (the pivot element). So, we need to find the pivot element using Binary Search.
If nums[mid-1] > nums[mid] then the pivot element is nums[mid], else if nums[mid] > nums[mid+1] return nums[mid+1] else if nums[mid] < nums[low] then high = mid-1. else low= mid+1.
Take example of [3, 4, 5, 1, 2]. if nums[mid] = 1, it satisfies first condition. If nums[mid] = 5, then it satisfies the second condition. If nums[mid] = 2, then we know came to know that we need to decrease high to find the pivot element. if all this condition does not implies increase low.
*/