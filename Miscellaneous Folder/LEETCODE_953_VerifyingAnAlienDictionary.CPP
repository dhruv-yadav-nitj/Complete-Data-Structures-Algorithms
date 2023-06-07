/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution{
public:
    bool isAlienSorted(vector<string>& words, string order){
        // code here
        unordered_map<char, int> m ;
        for(int i=0 ; i < order.length() ; i++){
            m[order[i]] = i ;
        }

        for(int i=1 ; i < words.size() ; i++){
            string temp1 = words[i -1] , temp2 = words[i] ;
            int len = min(temp1.length() , temp2.length()) ;
            bool flag= false ;
            for(int j =0 ; j < len ; j++){
                if(m[temp1[j]] < m[temp2[j]]){flag = true ; break ;} // since ye phle hi cchota nikal gya then we need not check any further --> for eg. take abhishek and saif --> abhishek has length greater but abhishek mein a phle hi aa gya which makes it lexicographically smaller
                else if(m[temp1[j]] > m[temp2[j]]){return false ;}
            }
            if(!flag and temp1.length() > temp2.length()){return false ;}
        }
        return true ;
    }
};
// @lc code=end

