
// https://practice.geeksforgeeks.org/problems/key-pair5616/1
// Key Pair
// GFG Self Paced DSA Course- Searching - Lecture No. 12
// Triplet Sum and 3Sum on Leetcode are more difficult question based on this problem

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Function to check if array has 2 elements
    // whose sum is equal to the given value
    bool hasArrayTwoCandidates(int arr[], int n, int x)
    {
        // to apply we must have sorted array
        sort(arr, arr + n);
        // the given array woudl be sorted obviously
        // we are gonna use Two-Pointer Approach and Binary Search
        int low(0), high(n - 1);
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (arr[low] + arr[high] == x)
            {
                return true;
            }
            else if (arr[low] + arr[high] < x)
            {
                low++;
            }
            else if (arr[low] + arr[high] > x)
            {
                high--;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends