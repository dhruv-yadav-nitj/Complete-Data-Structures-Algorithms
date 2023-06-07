//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
    // Similar LeetCode Question #11 Container with most Water
    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        /* 
        Idea 1: No water would be stored at corner towers, so start from index 1 and go till index n-2

        */
        int water(0);
        for (int i = 1; i < n-1; i++)
        {
            int lheight(arr[i]);
            for (int j = 0; j < i; j++)
            {
                lheight = max(lheight, arr[j]);
            }
            int rheight(arr[i]);
            for (int k = n - 1; k > i; k--)
            {
                rheight = max(rheight, arr[k]);
            }
            // Idea 2: Water stored in ith tower is equal to min(lheight, rheight)-(height of ith tower)
            water += (min(lheight, rheight) - arr[i]);
        }
        return water ;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends