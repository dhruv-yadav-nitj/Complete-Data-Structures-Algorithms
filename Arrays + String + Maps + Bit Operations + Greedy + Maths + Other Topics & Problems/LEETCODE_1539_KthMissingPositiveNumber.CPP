/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // code here

        int low = 0 , high = arr.size() ; // low and high denotes the indexes where we can roam

        while(low < high){
            int mid = low + (high - low) /2 ;

            if(arr[mid] - mid > k){high = mid ;}
            else{low = mid + 1 ;}
        }

        return low + k ;
    }
};
// @lc code=end

