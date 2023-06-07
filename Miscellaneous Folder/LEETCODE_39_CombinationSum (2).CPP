/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution{
    static void doWork(vector<int> nums, int index, vector<vector<int>> &ans, vector<int> ds, int target){
        // code here
        // base condition
        if(index == nums.size()){
            if(target==0){ans.push_back(ds) ;}
            return ;
        }
        
        // not pick
        doWork(nums, index+1, ans, ds, target) ;

        // pick
        if(target >= nums[index]){
            ds.push_back(nums[index]) ;
            doWork(nums, index, ans, ds, target - nums[index]) ;

            // yrr dekho agar pick kr lia phle tb pop krna hoga taaki not pick ho ske
            // but jb phle hi not pick kr rkha hain tb pop krne ka jroorat hi nahi
            // ds.pop_back() ; // taaki jb waapis yha pr aaye to jo last element insert hua tha wo pop ho ske
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target){
        // code here

        sort(candidates.begin(), candidates.end()) ;
        candidates.erase(unique(candidates.begin(), candidates.end()) , candidates.end()) ;

        vector<vector<int>> ans ; vector<int> ds ;
        doWork(candidates, 0, ans, ds, target) ;

        return ans ;
    }
};
// @lc code=end
