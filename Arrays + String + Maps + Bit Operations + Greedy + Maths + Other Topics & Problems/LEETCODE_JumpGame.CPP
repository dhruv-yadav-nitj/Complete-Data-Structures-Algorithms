/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool flag= false; int zero ;
        for(int i= nums.size() - 2 ; i >=  0; i--){
            if(nums[i] == 0 and !flag){
                flag = true ; zero = i ;continue;
            }

            if(flag){
                if(nums[i] > (zero - i)){
                    flag = false; continue;
                }
            }
        }
        return (!flag) ;
    }
};
// @lc code=end

