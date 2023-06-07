/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    static void doWork(vector<int> nums, vector<vector<int>> &ans, vector<int> ds , int index){
        // main function
        
        // base-condition
        ans.push_back(ds) ;

        for(int i=index ; i < nums.size() ; i++){

            // to avoid repeatetiveness
            if(i!= index and nums[i] == nums[i-1]){continue;}

            ds.push_back(nums[i]) ;
            doWork(nums, ans, ds, i+1) ;

            ds.pop_back() ;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums){
        // code here
        sort(nums.begin(), nums.end()) ;
        vector<vector<int>> ans ; vector<int> ds ;
        doWork(nums, ans, ds, 0) ; return ans ;
    }
};
// @lc code=end

// see note book for explanations