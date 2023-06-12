
// Allocate minimum number of pages
// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to find minimum number of pages.
    bool isPossible(int arr[], int n, int barrier, int m)
    {
        int allocated(0), count(1);
        for (int i = 0; i < n; i++)
        {
            if (allocated + arr[i] <= barrier)
            {
                allocated += arr[i];
            }
            else
            {
                count++;
                if (count > m or arr[i] > barrier)
                {
                    return false;
                }
                allocated = arr[i];
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M)
    {
        // acc to question its not possible to allocate 0 books to a student and its not possible to allocate all the books to the same student, but for sake of convenience and to start from somewhere lets take
        int low(0), high(accumulate(A, A + N, 0)) ;
        
        
        int ans(-1);
        if (M > N)
        {
            return -1;
        }
        while (low <= high)
        {
            int barrier = low + (high - low) / 2;
            if (isPossible(A, N, barrier, M))
            {
                high = barrier - 1;
                ans = barrier;
            }
            else
            {
                low = barrier + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends