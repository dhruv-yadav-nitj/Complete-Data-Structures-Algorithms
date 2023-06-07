// https://leetcode.com/problems/max-consecutive-ones/submissions/
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count(0), temp(0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                temp++;
            }
            else
            {
                count = max(count, temp);
                temp = 0;
            }
        }
        count = max(count, temp);
        return count;
    }
};