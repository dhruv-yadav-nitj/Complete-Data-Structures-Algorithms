
// find all the subset of a set using Power Set method
// https://leetcode.com/problems/subsets/
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> powerSet;
        int size = nums.size();
        for (int i = 0; i < pow(2, size); i++)
        {
            vector<int> temp;
            for (int j = 0; j < size; j++)
            {
                if ((i) & (1 << j))
                {
                    temp.push_back(nums[j]);
                }
            }
            powerSet.push_back(temp);
        }

        return powerSet;
    }
};