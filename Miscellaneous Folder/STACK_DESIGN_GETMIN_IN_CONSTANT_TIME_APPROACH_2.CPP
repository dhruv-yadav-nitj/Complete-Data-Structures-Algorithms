#include <bits/stdc++.h>
using namespace std ;

// https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?leftPanelTab=1

class SpecialStack {
    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
private:
    stack<int> s ; int mini;
public:
    void push(int data){
        if(s.empty()){
            mini = data ; s.push(data) ;
        }
        else if(data < mini){
            int val = 2*data - mini ;
            mini = data ;
            s.push(val) ;
        }
        else{
            s.push(data) ;
        }
    }

    int pop(){
        if(!s.empty()){
            if(s.top() > mini){
                int val = s.top() ; s.pop() ; return val ;
            }
            else{
                int valueToReturn = mini; // prevMini represents the value to be popped
                int newMini = 2*mini - s.top() ; s.pop() ;
                mini = newMini; return valueToReturn ;
            }
        }
        else{
            return -1;
        }
    }

    int top() {
        if(s.empty()){return -1;}
        else{
            if(s.top() < mini) {
                return mini ;
            }
            else{
                return s.top() ;
            }
        }
    }

    bool isEmpty() {
        return (s.empty()) ;
    }

    int getMin() {
        return (s.empty()) ? (-1) : (mini) ;
    }  
};