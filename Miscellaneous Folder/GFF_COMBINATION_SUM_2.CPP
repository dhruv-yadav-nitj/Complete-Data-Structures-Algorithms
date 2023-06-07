//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    static void doWork(vector<int> nums, int index, vector<vector<int>> &ans, vector<int> ds, int target){
        // code here
        if (target == 0){
            ans.push_back(ds); return;
        }

        for (int i = index; i < nums.size(); i++){
            // if its repeated
            if (i != index and nums[i] == nums[i - 1]){continue;}
            if (nums[i] > target){break;} // if nums[i] became greater than target

            ds.push_back(nums[i]);
            doWork(nums, i + 1, ans, ds, target - nums[i]);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
        
        // Write your code here
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; vector<int> ds;
        doWork(candidates, 0, ans, ds, target); return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++)
        {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++)
            {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends