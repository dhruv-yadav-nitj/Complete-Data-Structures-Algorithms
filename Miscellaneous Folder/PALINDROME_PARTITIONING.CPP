/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution{
    void doWork(string s, int index, vector<string> store, vector<vector<string>> &ans){
        // main-recursion-function
        if(index == s.length()){
            ans.push_back(store) ; return ;
        }

        for(int i= index ; i < s.length(); i++){
            if(isPalindrome(s, index, i)){
                store.push_back(s.substr(index, i - index + 1)) ;
                /*
                    string str="We think in generalities, but we live in details.";
                    string str2 = str.substr (3,5);     // "think"
                */
                doWork(s, i+1, store, ans) ;
                store.pop_back() ; // backtrack if its not a palindrome
            }
        }
    }

    bool isPalindrome(string s , int start , int end){
        while(start <= end){
            if(s[start] != s[end]){return false ;}
            start++ , end-- ;
        }
        return true ;
    }
public:
    vector<vector<string>> partition(string s){
        // code here
        vector<string> store ; // it would store the current set of partitioned strings
        vector<vector<string>> ans; // it would store all the possible store data structures
        doWork(s , 0 , store, ans); return ans ;
    }
};
// @lc code=end
