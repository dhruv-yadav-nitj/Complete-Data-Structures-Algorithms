#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

void heapify(vector<int> &arr , int n , int i){
    // use heapify algorithm

    // since the array is 0 - based indexing --> given in ques so left child would be become 2*i + 1 and right child would be 2*i + 2

    int smallest = i , left = 2* i + 1 , right = 2*i + 2 ;

    if(left < n and arr[left] < arr[smallest]){
        smallest = left ;
    }

    if(right < n and arr[right] < arr[smallest]) {
        smallest = right ;
    }


    if(smallest != i){
        swap(arr[smallest] , arr[i]) ;
        heapify(arr, n , smallest) ;
    }
    else{
        return ;
    }
}

vector<int> buildMinHeap(vector<int> &arr){
    // Write your code here

    int n = arr.size() ;

    for(int i = n / 2;  i >= 0 ; i--){
        heapify(arr, n , i) ;
    }
    

    return arr ;

}
