/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval){
        // code here
        vector<vector<int>> ans ;
        int i = newInterval[0] , j = newInterval[1] ;
        int k=0 ;

        // newInterval start hone se phle jitne interval khtm hote jaa rhe hain unko insert kr do
        while(k < intervals.size() and intervals[k][1] < i){
            ans.push_back(intervals[k]) ; k++ ;
        }
        
        while(k < intervals.size() and intervals[k][0] <= j){
            i = min(i , intervals[k][0]) ; j = max(j , intervals[k][1]) ;
            k++ ;
        }
        ans.push_back({i, j}) ;

        while(k < intervals.size()){
            ans.push_back(intervals[k]) ; k++ ;
        }
        return ans ;
    }
};
// @lc code=end
