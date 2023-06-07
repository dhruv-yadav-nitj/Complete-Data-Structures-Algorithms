// https://leetcode.com/problems/maximum-subarray/description/
// https://www.youtube.com/watch?v=w4W6yya1PIc

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxi(nums[0]), sum(0);
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};