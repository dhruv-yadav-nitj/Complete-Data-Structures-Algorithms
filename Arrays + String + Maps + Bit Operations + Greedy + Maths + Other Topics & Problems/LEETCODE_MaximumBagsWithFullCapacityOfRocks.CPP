/*
 * @lc app=leetcode id=2279 lang=cpp
 *
 * [2279] Maximum Bags With Full Capacity of Rocks
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

// Hint: Which bag should you fill completely first? --> which need less stone to reach to the full capacity

class Solution{
public:
    static bool customSort(const pair<int, int> &a, const pair<int, int> &b){
        return ((a.first - a.second) < (b.first - b.second)) ;
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks){
        int n= rocks.size() ; int count(0) ;
        for(int i=0; i < n;i++){
            if(rocks[i] == capacity[i]){count++ ;}
        }
        vector<pair<int, int>> temp ;
        for(int i = 0 ; i < n; i++){
            if(capacity[i] > rocks[i]){
                temp.push_back(make_pair(capacity[i] , rocks[i])) ;
            }
        }
        sort(temp.begin(), temp.end() , customSort) ;

        n = temp.size() ;
        for(int i= 0 ; i < n and additionalRocks > 0; i++){
            if(temp[i].first - temp[i].second <= additionalRocks){
                count++ ;
                additionalRocks = additionalRocks - (temp[i].first - temp[i].second) ;
                if(additionalRocks ==  0){break ;}
            }
        }
        return count ;
    }
};
// @lc code=end

