#include <bits/stdc++.h>
using namespace std ;

// https://leetcode.com/problems/min-stack/description/

// approach 1 : using stack : aux space : O(n)
class MinStack {
public:
    stack<int> s1, mini;

    void push(int val){
        s1.push(val) ; 
        (mini.empty()) ? (mini.push(val)) : (mini.push(min(mini.top(), val))) ;
    }
    
    void pop(){
        s1.pop() ; mini.pop() ;
    }
    
    int top(){
        return s1.top() ;
    }
    
    int getMin(){
        return mini.top() ;
    }
};