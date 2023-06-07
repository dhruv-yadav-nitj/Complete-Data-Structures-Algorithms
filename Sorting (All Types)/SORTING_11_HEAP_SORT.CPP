//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        // Your Code Here

        int largest = i  , left = 2* i + 1 , right = 2*i + 2 ;

        if(left < n  and arr[left] > arr[largest]){
            largest = left ;
        }

        if(right < n and arr[right] > arr[largest]){
            largest = right ;
        }

        if(largest != i ) {
            swap(arr[largest] , arr[i]) ;
            heapify(arr, n , largest) ;
        }
    }

public:
    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        // Your Code Here

        for(int i = n /2 ; i >= 0 ; i--){

            heapify(arr, n , i) ;

        }
        
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // code here

        // step 1 : call build heap --> wha se heapify mein jaaega

        buildHeap(arr, n ) ;

        // step2 : now we have a max heap --> heap sort using heapify

        int size = n ; 
        while(size > 1){
            swap(arr[0] , arr[size - 1]) ; size -- ;
            heapify(arr, size , 0) ; // now make the arr max heap again just exclude the last element --> bcz after swap the largest element got placed at its correct place
        }
    }
};