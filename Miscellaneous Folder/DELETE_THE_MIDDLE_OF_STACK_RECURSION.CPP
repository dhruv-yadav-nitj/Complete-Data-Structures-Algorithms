#include <bits/stdc++.h>
using namespace std ;

void deleteMid(stack<int> &s , int size, int count){

    // required base condition
    if(count == ceil(size/2.0)){
        s.pop() ; return ;
    }
    int num = s.top() ;

    s.pop() ;

    deleteMid(s, size , count+1) ;

    s.push(num);        
}

int main(int argc, char const *argv[])
{
    stack<int> s; int size; cin>> size ;
    for(int i= 1; i<= size ; i++){s.push(i) ;}
    return 0;
}
