#include <bits/stdc++.h>
using namespace std ;

queue<int> modifyQueue(queue<int> q, int k){
    stack<int> s ; int n= q.size();
    while(s.size() < k){
        int temp = q.front() ; s.push(temp) ; q.pop() ;
    }
    while(!s.empty()){
        q.push(s.top()) ; s.pop() ;
    }
    for(int i=0; i< n-k; i++){
        int temp= q.front(); q.pop() ; q.push(temp) ;
    }
    return q ;
}