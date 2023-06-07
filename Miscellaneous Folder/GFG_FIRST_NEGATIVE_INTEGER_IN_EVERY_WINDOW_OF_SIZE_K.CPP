#include <bits/stdc++.h>
using namespace std ;

// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// approach 1: using nested for-loop 
vector<int> doWork(vector<int> v, int k){
    vector<int> ans ;
    for(int i=0; i<= v.size()-k; i++){
        bool flag = false;
        for(int j= i; j < i+k; j++){
            if(v[j] < 0){
                ans.push_back(v[j]) ; flag = true ; break ;
            }
        }
        if(!flag){ans.push_back(0) ;}
    }
    return ans ;
}

// approach 2: using queue :-> TC = O(n) and SC = O(k)
vector<int> doWork(vector<int> v, int k){
    queue<int> q ; vector<int> ans ;
    
    // first deal with the first windows of size
    int i=0;
    while(i < k){
        if(v[i] < 0){q.push(i) ; i++ ;}
    }

    // now deal with the subsequent windows
    for( ; i< v.size(); i++){
        if(!q.empty()){
            ans.push_back(v[q.front()]) ;
        }
        else{
            ans.push_back(0) ;
        }

        while(!q.empty() and q.front() < i-k+1){
            q.pop() ;
        }

        if(v[i] < 0){q.push(i) ;}
    }

    // now deal with the last window
    if(!q.empty()){ans.push_back(v[q.front()]) ;}
    else{
        ans.push_back(0) ;
    }
    return ans ;
}

// we have a better approach to do the problem in O(n) TC and O(1) SC
vector<int> doWork (vector<int> v, int k){
    int index=0, element; vector<int> ans ;
    for(int i= k-1 ; i< v.size(); i++){
        while(index < i and (v[index] >= 0 or index <= i- k)){
            index++ ;
        }
        if(v[index] < 0 ){element = v[index] ;} 
        else{
            element =0 ;
        }
        ans.push_back(element) ;
    }
    return ans ;
}