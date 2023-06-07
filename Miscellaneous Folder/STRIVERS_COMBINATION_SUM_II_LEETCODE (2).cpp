class Solution
{
public:
    void doSolve(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &temp, int index, int target)
    {
        if (target==0)
        {
            ans.push_back(temp) ;
            return ;
        }

        // pick
        if (target >= candidates[index])
        {
            temp.push_back(candidates[index]);
            doSolve(candidates, ans, temp, index + 1, target - candidates[index]);
            temp.pop_back();
        }
        doSolve(candidates, ans, temp, index + 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        doSolve(candidates, ans, temp, 0, target);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};