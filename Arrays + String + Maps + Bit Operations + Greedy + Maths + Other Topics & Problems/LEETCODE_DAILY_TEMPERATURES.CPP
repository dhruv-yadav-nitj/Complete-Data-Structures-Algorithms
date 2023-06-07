#include <bits/stdc++.h>
using namespace std ;

// Approach - 1 : got TLE
// Time Complexity: O(n2)
// Brute Force: Use vector and two for loops
// efficient approach using stacks and concept of next smaller element

class Solution {
public:
    static int count(stack<int>s, int nums){
        int cnt(0) ; bool flag=false;
        while(!s.empty()){
            if(s.top() > nums){
                flag= true; break ;
            }
            cnt++ ; s.pop() ;
        }
        if(flag){return cnt;}
        else{
            return 0 ;
        }
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s; 
        for(int i= temperatures.size()-1 ; i >= 0 ; i--){
            s.push(temperatures[i]) ;
        }
        vector<int> ans ;
        while(!s.empty()){
            ans.push_back(count(s, s.top())) ;
            s.pop() ;
        }
        return ans ;
    }
};