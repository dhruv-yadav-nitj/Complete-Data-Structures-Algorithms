// BRUTE FORCE APPROACH : we can use recursion to generate all the possible permutations and then return kth permutation

// implementation of brute force approach :

/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution{
    void doWork(string s , vector<string> &ans , int index, int k){
        if(index == s.length()){
            ans.push_back(s) ; return ;
        }

        for(int i=index ; i  < s.length() ; i++){
            swap(s[index], s[i]) ;
            doWork(s , ans , index+1 , k) ;
            swap(s[index], s[i]);
        }
    }
public:
    string getPermutation(int n, int k){
        // code here
        vector<string> ans ;
        string nums = "" ;
        for(char i= '1' ; i <= '9' ; i++){
            nums += i ;
        }
        nums = nums.substr(0 , n) ; // is string ke permutation saare permutation nikal kr ans vector ka kth element return kr do
        doWork(nums,  ans , 0 , k) ;
        sort(ans.begin() , ans.end()) ;
        return ans[k-1] ;
    }
};
// @lc code=end
