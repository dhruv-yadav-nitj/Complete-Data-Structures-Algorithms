/*
 * @lc app=leetcode id=2244 lang=cpp
 *
 * [2244] Minimum Rounds to Complete All Tasks
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minimumRounds(vector<int>& tasks){
        // code here
        unordered_map<int, int> m ;
        int ans(0) ;
        for(auto &&k: tasks){
            m[k]++ ;
        }
        for (auto &&i : m){
            if(i.second == 1){return  -1 ;}
            if(i.second%3 ==0){ans += i.second/3 ;}

            else{
                ans += i.second /3 +1 ;
            }
        }
        return ans ;
        
    }
};
// @lc code=end

