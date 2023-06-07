#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

int main () {

    int arr[]  = {4, 1, 2, 3, 5, 7, 8} ;
    int size = sizeof(arr) / sizeof(arr[0]) ;
    priority_queue<int> pq ; // by default --> max heap

    // output 1
    for(int i =0 ; i < size ; i ++){
        cout << arr[i] << " ";
        pq.push(arr[i]) ;
    }cout << endl ;

    while(!pq.empty()){
        cout << pq.top() << " " ; pq.pop() ;
    }cout << endl ;

    // building min heap
    priority_queue<int  , vector<int> , greater<int>> minHeap ;

    // output 2
    for(int i =0 ;  i < size;  i++){
        minHeap.push(arr[i]) ;
    }

    // output 3
    while(!minHeap.empty()){
        cout << minHeap.top() << " " ; minHeap.pop() ;
    }cout << endl ;

}