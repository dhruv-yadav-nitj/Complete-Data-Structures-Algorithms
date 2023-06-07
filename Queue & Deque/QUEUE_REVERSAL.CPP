#include <bits/stdc++.h>
using namespace std ;

queue<int> rev(queue<int> q){
    vector<int> v ;
    while(!q.empty()){
        v.push_back(q.front()) ; q.pop() ;
    }
    reverse(v.begin(), v.end()) ;
    for(int i=0; i< v.size(); i++){
        q.push(v[i]) ;
    }
    return q; 
}

// one better approach would be to use stack
queue<int> rev(queue<int> q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front()) ; q.pop() ;
    }
    while(!s.empty()){
        q.push(s.top()) ; s.pop() ;
    }
    return q ;
}

// one more approach is to use recursion
void reverse(queue<int> &dq){
    if(dq.empty()){
        return ;
    }
    int nums = dq.front() ;
    dq.pop(); reverse(dq) ;

    // jb waapis aaega tb usme push krdo nums
    dq.push(nums) ;
}