class Solution
{
public:
    void combi(int index, int target, vector<int> &candidates, vector<vector<int>> &res, vector<int> &temp)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (i != index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            combi(i + 1, target - candidates[i], candidates, res, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> res;
        combi(0, target, candidates, res, temp);
        return res;
    }
};