/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int trap(vector<int> &height){
        // code here
        vector<int> l , r ;
        l.push_back(height[0]) ; r.push_back(height[height.size() -1]) ;
        for(int i= 1 ; i< height.size() ; i++){
            l.push_back(max(l.back(), height[i])) ;
            r.push_back(max(r.back() , height[height.size() -1 - i])) ;
        }
        reverse(r.begin() , r.end()) ;
        int ans = 0 ;
        for(int i = 0 ; i < height.size() ; i++){
            ans += min(l[i] , r[i]) - height[i];
        }
        return ans ;
    }
};
// @lc code=end
