
// this file contains:
// implementing Stacks using Arrays

#include <bits/stdc++.h>
using namespace std ;

class Stack{
public:
    // a stack contains a top, size and an array
    int top ; int size ; int *arr ;

    Stack(int size)
    {
        top = -1 ; this-> size = size; arr = new int[size] ;
    }

    // now we are having 4 different functions for a stack: Push, Pop, Peek, isEmpty

    void push(int new_dat){
        // first lets check if there's space available in the stack or not
        if(size-top > 1) {top++ ; arr[top] = new_dat ;}
        else{
            cout << "Stack OverFlow" << endl;
        }
        // imagine a vertical container
    }

    void pop(){
        if(top >= 0) {top-- ;}
        else{
            cout << "Stack Empty" << endl ;
        }
    }

    int peek(){
        if(top >= 0) {return arr[top] ;}
        else{
            cout << "Stack is Empty." << endl; return -1; 
        }
    }

    bool isEmpty(){
        if(top==-1) {return true;}
        else{return false;}
    }
};

int main(int argc, char const *argv[])
{
    Stack s(4) ;
    s.push(4) ; s.push(3) ; s.push(2) ; s.push(1) ; cout << s.peek() << endl; 

    // dont use top in place of peek bcz top is some kind of reserved keyword or like that, it gives error

    s.pop() ; cout << s.peek() << endl ;
    s.pop() ; cout << s.peek() << endl ;
    s.pop() ; cout << s.peek() << endl ;
    s.pop() ;

    if(s.isEmpty()) {cout << "YES" << endl;} else{cout << "NO" << endl;}

    // using stl - revision
    stack<int> temp ; temp.push(4) ; temp.push(3) ; temp.push(2) ; temp.push(1) ;
    cout << temp.top() << endl ;
    temp.pop() ; cout << temp.top() << endl;
    if(temp.empty()) {cout << "YES" << endl;} 
    else{cout << "NO" << endl;}
    cout << temp.size() << endl;

    return 0;
}
