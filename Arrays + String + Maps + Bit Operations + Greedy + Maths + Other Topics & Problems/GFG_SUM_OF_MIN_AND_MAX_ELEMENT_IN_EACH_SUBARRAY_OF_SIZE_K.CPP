#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
#define loop(i, low, high) for(int i= low; i < high;i++) 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Efficient Approach : Time Complexity : O(n) ; Aux Space : O(k)

int doWork (int *arr, int n, int k){
    // form two deques to store mini and maxi of each window
    deque<int> maxi, mini ;
    // lets go for the first window
    for(int i=0; i < k; i++){

        // aisa krne se na maxi mein to left->right decreasing order mein elements sort ho jaaenge aur mini mein left-> right increasing order mein --> aisa krne se jo maxi.front() hoga wo hmesa largest element in that window ko point krega aur mini.front() wo hmesa smallest element in that window point krega
        while(!maxi.empty() and arr[maxi.back()] <= arr[i]){
            maxi.pop_back() ;
        }
        while(!mini.empty() and arr[mini.back()] >= arr[i]){
            mini.pop_back() ;
        }

        maxi.push_back(i) ; mini.push_back(i) ;
    }
    // final ans
    int ans = arr[maxi.front()] + arr[mini.front()] ;

    for(int i=k ; i < n ; i++){
        // remove all the elements in queue which does not lie in the current window
        while(!maxi.empty() and maxi.front() < i-k+1){
            maxi.pop_front() ;
        }
        while(!mini.empty() and mini.front() < i-k+1){
            mini.pop_front() ;
        }

        // now add new elements in the queue again
        while(!maxi.empty() and arr[maxi.back()] <= arr[i]){
            maxi.pop_back() ;
        }
        while(!mini.empty() and arr[mini.back()] >= arr[i]){
            mini.pop_back() ;
        }

        maxi.push_back(i) ; mini.push_back(i) ;
        // using the same code as for the first window

        ans += arr[maxi.front()] + arr[mini.front()] ;
    }
    return ans ;
}

int main()
{
    IOS;
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int k = 4 ;

    // answer should be 18 --> (-1 + 7)+(-3 + 7)+(-3+7)+(-3+7) = 18
    cout << doWork(arr, sizeof(arr)/sizeof(arr[0]), k) << endl ;

    return 0;
}