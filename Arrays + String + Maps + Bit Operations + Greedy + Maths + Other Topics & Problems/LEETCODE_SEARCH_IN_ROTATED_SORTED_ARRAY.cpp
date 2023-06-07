
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
    // it was given that the array does not contain duplicate elements and its two halves are sorted in ascending order.
    int search(vector<int> &nums, int target)
    {
        int low(0), high(nums.size() - 1), mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            // now lets check if the left half is sorted or not
            if (nums[low] <= nums[mid]) // if condition implies then it means that left half is sorted
            {
                if (target >= nums[low] and target <= nums[mid])
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // if the condition does not implies then it means that left half if not sorted and we are standing at the pivot element
            else
            {
                // lets check if the right half has target or not
                if (target >= nums[mid] and target <= nums[high])
                {
                    low = mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};