#include <bits/stdc++.h>
using namespace std ;

class MinStack {
private:
    stack<long long> s; long long mini ;
public:
    void push(long long val){
        if(s.empty()){
            mini = val ; s.push(val) ;
        }
        else{
            if(val > mini){
                s.push(val) ;
            }
            else{
            // now means we would be getting new mini and we would have to push the modified value
                long long valToPush = 2* val - mini ;
                mini = val ;
                s.push(valToPush) ;
            }
        }
    }
    
    void pop(){
        if(s.top() < mini){
            // iska mtlb we have to now modify the mini since the smallest value till now is going to be popped
            long long valToBePopped = mini ;
            long long newMini = 2*mini - s.top() ;
            mini = newMini ; s.pop() ;
        }
        else{
            // normal pop
            s.pop() ;
        }
    }
    
    long long top(){
        if(s.top() < mini){
            return (mini) ;
        }
        else{
            return s.top();
        }
    }
    
    long long getMin(){
        return mini ;        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * long long param_3 = obj->top();
 * long long param_4 = obj->getMin();
 */