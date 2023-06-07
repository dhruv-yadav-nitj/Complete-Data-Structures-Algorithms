//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


// approch 1 : sum nikal lo saare subarray ka --> store kra lo ek vector mein --> sort kr do vector ko --> return the kth largest number --> time complexity : O(N^2 * no of subarrays * log(no. of subarrays))


// approach 2: sb kuch waise hi kro bs kth largest nikalne k lie min heap ka use kr lo

class Solution
{
public:
    int kthLargest(vector<int> &Arr, int N, int K){

        // code here
        vector<int> sum ;
        for(int i = 0 ; i <  N ; i++){
            int temp = 0 ;

            for(int j = i ; j < N ; j++){

                temp += Arr[j] ; sum.push_back(temp) ;
            }

        }

        // now we have a vector of some elements --> use min heap to find the kth largest element from this vector
        priority_queue<int, vector<int> , greater<int>> pq ;
        
        for(int i =0 ; i < K; i++){pq.push(sum[i]) ;}

        for(int i = K ; i <  sum.size() ; i++){

            if(sum[i] > pq.top()){
                pq.pop() ; pq.push(sum[i]) ;
            }
        }

        return pq.top() ;

    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N;
        cin >> K;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }
        Solution ob;
        int ans = ob.kthLargest(Arr, N, K);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends