
// https://leetcode.com/problems/maximum-difference-between-increasing-elements/

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int mini(nums[0]), diff(0);
        for (int i = 1; i < nums.size(); i++)
        {
            mini = min(mini, nums[i]);
            diff = max(diff, nums[i] - mini);
        }
        if (diff > 0)
        {
            return diff;
        }
        else
        {
            return -1;
        }
    }
};