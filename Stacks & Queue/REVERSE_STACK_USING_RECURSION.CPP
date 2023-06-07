#include <bits/stdc++.h>
using namespace std ;

void atBottom(stack <int>&s, int nums){
    if(s.empty()){
        s.push(nums) ; return ;
    }
    int temp = s.top() ; s.pop() ; 
    atBottom(s, nums) ;
    s.push(temp) ;
}

void reverse(stack<int> &s){
    // we would be using the insert element at bottom of the stack for this problem too

    // base condition
    if(s.empty()){
        return ;
    }
    int nums; nums = s.top() ; s.pop();
    reverse(s) ;
    atBottom(s, nums) ;
}

void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " " ; s.pop() ;
    }cout << endl ;
}

int main(int argc, char const *argv[])
{
    stack<int> s ; int size; cin >> size ;
    for(int i=size; i>= 1; i--){
        s.push(i) ;
    }

    cout << "Before Reversal: " ; print(s) ;
    reverse(s); cout << "After Reversal: " ; print(s) ;
    return 0;
}