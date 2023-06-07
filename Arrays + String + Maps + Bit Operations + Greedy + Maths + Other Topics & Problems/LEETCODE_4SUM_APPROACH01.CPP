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
        sort(nums.begin(), nums.end()) ;

        // fix three pointers --> fix three numbers and find the 4th number using binary search
        int n= nums.size() ; set<vector<int>> s ;
        for(int i=0; i< n; i++){
            for(int j = i+1 ; j < n; j++){
                for(int k = j+1; k < n; k++){

                    long long hole = (long long)nums[i] + nums[j] + nums[k] ; hole = (long long)target - hole ;

                    int start = k + 1 , end = n ; vector<int> v ;
                    while(start < end){
                        int mid = start + (end - start)/2 ;
                        if(nums[mid] == hole){
                            v.push_back(nums[i]) ;
                            v.push_back(nums[j]) ;
                            v.push_back(nums[k]) ;
                            v.push_back(nums[mid]); break ;
                        }
                        else if(nums[mid] < hole){
                            start = mid + 1 ;
                        }
                        else{end = mid  ;}
                    }
                    s.insert(v) ;
                }
            }
        }

        vector<vector<int>> ans ;

        for (auto &&i : s){
            if(i.size() > 0){
                ans.push_back(i) ;
            }
        }
        return ans ;

        // Time Complexity: for sorting --> O(nlogn) + three nested loops --> O(n^3) + binary search --> O(logn)
        // Net Time Complexity: O(nlogn + n^3xlogn)
        
    }
};
// @lc code=end
