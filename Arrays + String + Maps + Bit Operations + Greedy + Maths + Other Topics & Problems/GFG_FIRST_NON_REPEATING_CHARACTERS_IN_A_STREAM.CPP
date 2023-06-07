#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
	string FirstNonRepeating(string A){
        // we need to have two data stuctures for this purpose
        // one would be queue and another would be a hash map
        queue<char> q; unordered_map<char, int> m ;
        string ans = "";
        for(int i=0; i< A.length() ; i++){
            m[A[i]]++ ;
            if(m[A[i]] == 1){q.push(A[i]) ;}
            while(!q.empty() and m[q.front()] > 1){
                q.pop() ;
            }

            if(!q.empty()){
                ans += q.front() ;
            }
            else{
                ans += '#' ;
            }
        }
        return ans ;
    }
};