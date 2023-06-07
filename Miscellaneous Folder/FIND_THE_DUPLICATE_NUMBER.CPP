#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/

class Solution{
public:
    int findDuplicate(vector<int> &nums){
        // CODE HERE
        
        // approach 1: using hashmap
        unordered_map<int, int> m ;
        for(int i=0 ; i < nums.size() ; i++){
            m[nums[i]]++ ;
            if(m[nums[i]] > 1){return nums[i] ;}
        }
        return -1 ;

        // approach 2: sort the array and return that element which occurs more than one time

        // approach 3:
        // marking visited value within the array

        // since we know that the elements lie in the range [1, n] where the size of array is n+1
        for(auto &&i: nums){
            int idx = abs(i) ;
            if(nums[idx] < 0){return idx ;}
            nums[idx]= -nums[idx] ;
        }
        return -1 ;
    }
};