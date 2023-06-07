#include <bits/stdc++.h>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

// Approach #1 : using BASIC UNDERSTANDING : 100% fast on LeetCode

class Solution{
public:
    string longestCommonPrefix(vector<string> &strs){
        // code here
        sort(strs.begin() , strs.end()); // ye sort hua hain lexicographic order mein
        int n = strs.size() ;

        // sort krne k baad ab dekho jo bhi longest common prefix hoga wo best case mein jo shortest string hain na wo ho skta hain
        int len = min(strs[0].length() , strs[n - 1].length()) ;
        string ans = "" ;
        for(int i=0 ; i < len ; i++){
            if(strs[0][i] == strs[n-1][i]){
                ans += strs[0][i] ;
            }
            else{break ;}
        }
        return ans ;
    }
};