/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// dekho ye ques pdh kar dimaag mein ek baar ye bhi aa skta hain ki str1 k saare permutations nikaal kr ek ek ko match kr lete hain --> believe mein isase bakwaas idea nhi ho skta

// so yha pr hm lgaaenge thoda sa common sense

/* 
Approach:
take two vector --> ek map mein to string one k hr ek letter ka freq store kr lo --> then second map mein kya kro ki sliding windows technique lgao --> jitna size hain str 1 ka utne length mein aane waale str2 k letters ka freq match kr lo
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2){

        vector<int> temp1(26, 0), temp2(26, 0) ;
        for(int i = 0; i < s1.size() ; i++){
            temp1[s1[i] - 'a']++ ;
        }

        int start = 0, end = 0 ;
        while(end < s2.length()){
            temp2[s2[end] - 'a']++ ;

            if(end - start + 1 == s1.length()){
                if(temp1 == temp2){return true ;}
            }

            if(end - start + 1 < s1.length()){
                end ++ ;
            }
            else{
                temp2[s2[start] - 'a']-- ;
                start++ , end++ ;
            }
        }
        return false ;
        
    }
};
// @lc code=end

