class Solution
{
public:
    void doSolve(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int index)
    {
        if (index == nums.size())
        {
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        // in place of not pick we can do the following, what if we dont take the element first
        // doSolve(nums, ans, temp, index + 1);

        // pick
        temp.push_back(nums[index]);
        doSolve(nums, ans, temp, index + 1);

        // not pick
        temp.pop_back();
        doSolve(nums, ans, temp, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        doSolve(nums, ans, temp, 0);

        set<vector<int>> s;
        for (int i = 0; i < ans.size(); i++)
        {
            s.insert(ans[i]);
        }
        ans.clear();
        for (auto x : s)
        {
            ans.push_back(x);
        }

        return ans;
    }
};