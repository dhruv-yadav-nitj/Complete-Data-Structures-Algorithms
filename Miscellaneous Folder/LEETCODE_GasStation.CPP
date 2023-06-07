/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int amt =0, xtra=0, start =0; int n= gas.size() ;
        for(int i=0; i< n; i++){
            amt=  amt + (gas[i] - cost[i]) ;
            if(amt < 0){
                xtra = xtra + amt ; amt =0 ;
                start = i+1 ;
            }
        }
        if(amt + xtra >=0 ){return start ;}
        else{
            return -1 ;
        }
    }
};
// @lc code=end

