#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;


// approach 1 : sort the arr using stl , return the (k-1)th element


// approach 2 : use min heap --> time : O(k + nlogn) --> space : O(n)

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here

        priority_queue<int, vector<int>  , greater <int>> pq ;
        for(int i = l ; i <= r ; i++){
            pq.push(arr[i]) ;
        }

        int count= 0 ;
        while(count < k){
            pq.pop() ; count++ ;
        }

        return pq.top() ;
    }
};

// approach 3 : using max heap --> best --> time : O(K + (N-K) * Log K) --> space : O(k)

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here

        int n = r + 1 ;

        // make a max heap
        priority_queue<int> pq ;

        // step 1 : push first k elements of arr in the pq --> the top element would be the largest element of the first windows of size k
        for(int i= 0 ; i < k ; i++){

            pq.push(arr[i]) ;
        }

        // step 2: move further in the arr and if the curr element is smaller than the top of pq --> pop pq and insert the curr element in the pq

        for(int i = k ; i < n ; i++){

            // this step is the 'jaan' of this method
            if(arr[i] < pq.top()){
                pq.pop() ; pq.push(arr[i]) ;
            }
        }

        // step 3: return pq.top() 
        return pq.top() ;

        // summary : phle hmne max-heap mein first k element ghusa die --> jo first k elements ka largest rha hoga wo sbse top pr hain wo top wala largest hone k saath saath first k sized window ka kth smallest element bhi hain --> pura array traverse krne k baad bhi heap ki size k hi rhegi --> so iska mtlb ki kth smallest element of the net arryay would be at the top after the step 2 operation
    }
};