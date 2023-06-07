/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    static void doWork(vector<int> nums, int index, vector<vector<int>> &ans){
        // main function
        if(index == nums.size()){ans.push_back(nums) ; return ;}

        for(int i=index; i  < nums.size() ; i++){
            swap(nums[i], nums[index]) ;
            doWork(nums, index+1 , ans) ;
            swap(nums[i] , nums[index]) ;
        }
    }
public:
    vector<vector<int>> permute(vector<int> &nums){
        // code here
        vector<vector<int>> ans ;
        doWork(nums, 0, ans) ; return ans ;
    }
};
// @lc code=end
