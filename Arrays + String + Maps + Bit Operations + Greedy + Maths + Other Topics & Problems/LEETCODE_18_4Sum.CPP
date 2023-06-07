/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        // code here

        if(nums.size() < 4){return {} ;}

        sort(nums.begin(), nums.end()); int n = nums.size() ; set<vector<int>> s ;

        for(int i=0; i < n - 3 ; i++){
            for(int j = i +1 ; j < n - 2; j++){
                long long hole = (long long)nums[i] + nums[j] ; hole = (long long)target - hole ;

                int front = j +1 , back = n -1 ;
                while(front < back){
                    if(nums[front] + nums[back] == hole){
                        s.insert({nums[i], nums[j] , nums[front], nums[back]}) ;
                        front++ ;
                    }

                    else if(nums[front] + nums[back] < target){front++ ;}
                    else{back-- ;}
                }
            }
        }
        vector<vector<int>> ans ;
        for(auto &&x : s){
            ans.push_back(x) ;
        }
        return ans ;
    }
};
// @lc code=end
