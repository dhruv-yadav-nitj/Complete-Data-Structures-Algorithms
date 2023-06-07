
// https://practice.geeksforgeeks.org/problems/maximum-occured-integer4602/1
// Given n integer ranges, the task is to find the maximum occurring integer in these ranges. If more than one such integer exists, find the smallest one. The ranges are given as two arrays L[] and R[].  L[i] consists of starting point of range and R[i] consists of corresponding end point of the range.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // L and R are input array
    // maxx : maximum in R[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in L[] and R[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int L[], int R[], int n, int maxx)
    {
        vector<int> v(maxx, 0);
        for (int i = 0; i < n; i++)
        {
            v[L[i]]++;
            if (R[i] < maxx - 1)
            {
                v[R[i] + 1]--;
            }
        }
        int maxm(0), ans(0);
        for (int i = 1; i < maxx; i++)
        {
            v[i] += v[i - 1];
            if (maxm < v[i])
            {
                maxm = v[i];
                ans = i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        int n;

        // taking size of array
        cin >> n;
        int L[n];
        int R[n];

        // adding elements to array L
        for (int i = 0; i < n; i++)
        {
            cin >> L[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++)
        {

            cin >> R[i];
            if (R[i] > maxx)
            {
                maxx = R[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(L, R, n, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends