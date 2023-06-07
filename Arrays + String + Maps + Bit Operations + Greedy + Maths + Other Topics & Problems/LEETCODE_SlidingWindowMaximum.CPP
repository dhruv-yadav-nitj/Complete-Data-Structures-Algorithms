/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;
// well this ques is totally the LITE version of the problem Sum of Mini and Maxi Element in each Subarray of size k in queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        deque<int> temp ; int n = nums.size() ;
        // dealing with the first window
        for(int i=0; i < k ; i++){
            while(!temp.empty() and nums[temp.back()] <= nums[i]){
                temp.pop_back() ;
            }
            temp.push_back(i) ;
        }
        vector<int> ans ;
        ans.push_back(nums[temp.front()]) ;

        for(int i= k ; i < n; i++){
            
            // removing the element which does not lie in the current window
            while(!temp.empty() and temp.front() < i-k+1){
                temp.pop_front() ;
            }

            // adding the element according to the current window
            while(!temp.empty() and nums[temp.back()] <= nums[i]){
                temp.pop_back() ;
            }
            temp.push_back(i) ;

            ans.push_back(nums[temp.front()]) ;
        }
        return ans ;
    }
};
// @lc code=end