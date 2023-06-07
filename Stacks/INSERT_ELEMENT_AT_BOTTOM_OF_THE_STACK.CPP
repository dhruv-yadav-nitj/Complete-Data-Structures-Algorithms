#include <bits/stdc++.h>
using namespace std ;

void insertAtBottom(stack <int>&s  , int inp){
    // base condition
    if(s.empty()){
        s.push(inp) ; return ;
    }

    int num = s.top() ;
    s.pop() ; insertAtBottom(s, inp) ;

    s.push(num) ;
}

int main(int argc, char const *argv[])
{
    stack<int> s ; int size; cin>> size ;
    for(int i= size; i >= 1 ; i--){
        s.push(i) ;
    }
    int inp; cin >> inp;
    insertAtBottom(s, inp) ;

    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop() ;
    }cout << endl ;

    return 0;
}
