class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if ((mid == 0 or nums[mid] >= nums[mid - 1]) and (mid == n - 1 or nums[mid] >= nums[mid + 1]))
            {
                return mid;
            }
            else if (mid > 0 and nums[mid - 1] >= nums[mid])
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