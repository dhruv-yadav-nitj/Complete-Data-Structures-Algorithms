/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std ;

class MyStack{
    queue<int> q1 ;
public:
    void push(int x){
        q1.push(x) ;
    }
    
    int pop(){
        if(q1.empty()){return -1 ;} // if empty then return -1 ;

        // else
        queue<int> q2 ;
        while(q1.size() > 1){
            q2.push(q1.front()) ; q1.pop() ;
        }
        int temp = q1.front() ; q1.pop() ;
        q1.swap(q2) ;
        return temp ;
    }
    
    int top(){
        if(q1.empty()){return -1 ;} // if empty then return -1 ;

        // else
        return q1.back() ;
    }
    
    bool empty(){
        return (q1.empty()) ;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

