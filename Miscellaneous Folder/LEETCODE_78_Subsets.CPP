/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

class Solution {
    static void doWork(vector<int> nums, int index, vector<vector<int>>&ans, vector<int> ds){
        // main function

        // base condition
        if(index == nums.size()){ans.push_back(ds) ; return ;}

        // not-pick
        doWork(nums, index+1, ans, ds) ;

        // pick
        ds.push_back(nums[index]) ;
        doWork(nums, index+1, ans, ds) ;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums){
        // code here

        // using pick and not-pick technique

        vector<vector<int>> ans ; vector<int> ds ;
        doWork(nums, 0, ans, ds) ;
        return ans ;
    }
};
// @lc code=end

