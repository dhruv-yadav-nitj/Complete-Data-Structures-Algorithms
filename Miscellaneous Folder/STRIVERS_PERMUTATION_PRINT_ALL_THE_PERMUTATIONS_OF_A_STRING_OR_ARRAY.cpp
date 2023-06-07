
// Problem Statement: Print all the permutations of a string or an array.
// Note: Total number of permutations = (n)! , where n is the size of array or the length of the string.
// Example: I/P vector : {1, 2, 3} then the possible permutations would be :
// {1, 2, 3} , {1, 3, 2} , {2, 1, 3} , {2, 3, 1} , {3, 1, 2} , {3, 2, 1}

// https://leetcode.com/problems/permutations/submissions/

class Solution
{
private:
    void doSolve(vector<int> &nums, vector<vector<int>> &ans, int index)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            doSolve(nums, ans, index + 1);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        doSolve(nums, ans, 0);
        return ans;
    }
};