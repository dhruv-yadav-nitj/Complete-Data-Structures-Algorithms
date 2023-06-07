#include <bits/stdc++.h>
using namespace std ;

// approach 1: time complexity : O(n) and Space Complexity: O(n)
void doWork(queue <int> &q){
    // queue is always of even length
    int n= q.size() ;
    queue<int> q1, q2 ;
    while(q1.size() < n/2){
        q1.push(q.front()); q.pop() ;
    }
    while(q2.size() < n/2){
        q2.push(q.front()) ; q.pop() ;
    }
    while(q.size() < n){
        q.push(q1.front()) ; q1.pop() ;
        q.push(q2.front()) ; q2.pop() ;
    }
}

// approach 2: Time Complexity: O(n) and Space Complexity: O(n/2)
void doWork(queue<int> q){
    // instead of using two new queues, this question can be done using a single new queue
    queue<int> new_q ; int n = q.size() ;
    while(new_q.size() < n/2){
        new_q.push(q.front()); q.pop() ;
    }
    while(!new_q.empty()){
        q.push(new_q.front()) ; new_q.pop() ;
        int temp = q.front() ; q.pop() ; q.push(temp) ;
    }
}

// approach 3: using stacks
void doWork (queue <int> q){
    stack<int> temp ; // used to store the first half of q (two different times)
    int n = q.size() ;
    while(temp.size() < n/2){
        temp.push(q.front()) ; q.pop() ;
    }
    while(!temp.empty()){
        q.push(temp.top()) ; temp.pop() ;
    }
    for(int i=1 ; i <= n/2 ;i++){
        int temp=q.front(); q.push(temp) ;
        q.pop() ;
    }
    while(temp.size() < n/2){
        temp.push(q.front()) ; q.pop() ;
    }
    while(!temp.empty()){
        q.push(temp.top ()) ; temp.pop() ;
        q.push(q.front()) ; q.pop() ;
    }
}