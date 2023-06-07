#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// time complexity : O(nlogn)


// ye ques mereko is time smjh nhi aaya

// custom functions

int signum(int a, int b){
    if(a == b){return 0 ;}
    else if(a > b){
        return 1 ;
    }
    else{return -1 ;}
}

void returnMedian(int curr , priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median){

    switch(signum(maxHeap.size() , minHeap.size())){

        case 0 :
            if(curr > median){
                minHeap.push(curr) ; median = minHeap.top() ;
            }
            else{
                maxHeap.push(curr) ; median = maxHeap.top() ;
            }
            break ;
        case 1:
            if(curr > median){
                minHeap.push(curr) ; median= (maxHeap.top() + minHeap.top())/2 ;
            }
            else{
                minHeap.push(maxHeap.top()) ; maxHeap.pop() ; maxHeap.push(curr) ; median= (maxHeap.top() + minHeap.top())/2 ;
            }
            break ;
        case -1:
            if(curr > median){
				maxHeap.push(minHeap.top()); minHeap.pop();
                minHeap.push(curr);
				median = (minHeap.top() + maxHeap.top())/2;
			}
			else{
				maxHeap.push(curr);
				median = (minHeap.top() + maxHeap.top())/2;
			}
			break;
    }
}

vector<int> findMedian(vector<int> &arr, int N){

    // code here

    // prerequisites
    vector<int> ans ; priority_queue<int> maxHeap ; priority_queue<int, vector<int>, greater<int>> minHeap ;
    int median =0 ; // initially taken

    for(int i =0 ;i  < N ; i++){
        returnMedian(arr[i] , maxHeap , minHeap , median) ; ans.push_back(median) ;
    }

    return ans ;

}