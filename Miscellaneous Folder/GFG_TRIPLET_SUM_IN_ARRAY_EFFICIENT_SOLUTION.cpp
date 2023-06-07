//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        // Time Complexity = O(n^2);
        // Aux Space = O(1)
        sort(A, A + n);
        for (int i = 0; i < n; i++)
        {
            int reqSum = X - A[i];
            // now we would apply the Key Pair Problem Approach (based on Two Pointers)
            int low = i + 1, high = n - 1;
            while (low < high)
            {
                if (A[low] + A[high] == reqSum)
                {
                    return true;
                }
                else if (A[low] + A[high] < reqSum)
                {
                    low++;
                }
                else if (A[low] + A[high] > reqSum)
                {
                    high--;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends