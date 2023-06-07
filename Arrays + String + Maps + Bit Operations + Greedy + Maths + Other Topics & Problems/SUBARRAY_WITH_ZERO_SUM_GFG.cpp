//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        int sum(0);
        // method 1:- using map
        /* map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            // Logic: Let say we have a subarray sum as A and we added another subarray sum B in it and got A again, this means B is 0.
            sum += arr[i];
            if (m[sum] >= 1 or sum == 0)
            {
                return true;
            }
            else
            {
                m[sum]++;
            }
        } */

        // method 2:- using set
        unordered_set<int> checkSum;
        int sum(0);
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (checkSum.find(sum) != checkSum.end() or sum == 0)
            {
                return true;
            }
            checkSum.insert(sum);
        }

        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
// } Driver Code Ends