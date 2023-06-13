// Date: 13 June, 2023
#include <bits/stdc++.h>
using namespace std ;

class Solution{
public:	
    void heapify (int arr[] , int n, int i){
        int largest= i, left = 2*i + 1 , right = 2*i +2 ;
        if(left < n and arr[left] > arr[largest]){
            largest = left ;
        }
        if(right < n and arr[right] > arr[largest]){
            largest = right ;
        }

        if(largest != i){
            swap(arr[largest] , arr[i]) ;
            heapify(arr, n , largest) ;
        }
    }
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here

        // approach : we would build a heap of size n

        for(int i= n/2 ; i >= 0; i--){
            heapify(arr, n , i) ;
        }

        // so now the largest element would be at the first index
        int size = n , temp = k ;
        while(k > 0){
            swap(arr[0] , arr[size-1]) ; size-- ; k-- ;
            heapify(arr, size , 0) ;
        }

        vector<int> ans ;
        for(int i = n-1 ; i > (n-1-temp) ; i--){
            ans.push_back(arr[i]) ;
        }

        return ans ;
	}

};