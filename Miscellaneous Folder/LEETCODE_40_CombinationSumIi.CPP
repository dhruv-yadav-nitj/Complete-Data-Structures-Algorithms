#include <bits/stdc++.h>
using namespace std ;

class Solution
{
private:
    static void doWork(vector<int> nums, int index, int target, vector<vector<int>> &ans, vector<int> &ds){
        // code here
        if(target == 0){
            ans.push_back(ds) ; return ;
        }

        for(int i=index ; i < nums.size(); i++){
            if(i > index and nums[i] == nums[i-1]){continue;}
            if(target >= nums[i]){
                ds.push_back(nums[i]) ;
                doWork(nums, i+1, target-nums[i], ans, ds) ;
                ds.pop_back() ;
            }
            else{
                // means nums[i] > target
                break ;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
        // code here
        sort(candidates.begin() , candidates.end()) ;
        vector<vector<int>> ans ; vector<int> ds ;
        doWork(candidates, 0, target, ans, ds) ; return ans ;
    }
};

// see notebook for notes , time complexity , space complexity