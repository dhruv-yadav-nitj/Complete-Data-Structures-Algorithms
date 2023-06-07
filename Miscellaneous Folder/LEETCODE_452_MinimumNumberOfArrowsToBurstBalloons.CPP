/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    static bool custom(const vector<int> &v1,const vector<int> &v2){
        // sort the balloons according to the starting index of the balloons... if the starting index of two balloons are same then we should place those balllons first whose ending index are smaller
        if(v1[0]==v2[0]){return v1[1] < v2[1] ;}
        return v1[0] < v2[0] ;
    }
// jo ith ballon ka end point hoga wo (i-1)th balloon k start aur end points k beech lie krna chaie
    int findMinArrowShots(vector<vector<int>>& points){
        // code here
        if(points.size() == 0){return 0 ;}
        sort(points.begin(), points.end(), custom);
        int n= points.size() ;
        // dekho start to hmne sort kr dia ab wo decreasing order mein hi sorted hoga
        int i=0 , miniEnd = INT_MAX, count(1), maxiStart(INT_MIN) ;
        miniEnd = points[0][1], i =1, maxiStart= points[0][0] ;
        while(i < n){
            if(points[i][0] <= miniEnd and points[i][0] >= maxiStart){
                miniEnd= min(miniEnd, points[i][1]) ; maxiStart= max(maxiStart, points[i][0]);
                // count would not change in this case --> when the current ballons is lying in the range of the smallest balloon till now which can be shot with the same arrow and whose starting index is also lying in the range of the right-most ballon in the current count

                /* basically we need this type of arrangement
                            ---------------  -----------
                                --------        ------------
                                  -----          ------
                                    --             ---
                */
            }
            else{
                miniEnd= points[i][1]; count++, maxiStart= points[i][0] ;
            }

            i++; // ye ek cheej jo hmesa honi hain
        }
        return count;
    }
};
// @lc code=end

