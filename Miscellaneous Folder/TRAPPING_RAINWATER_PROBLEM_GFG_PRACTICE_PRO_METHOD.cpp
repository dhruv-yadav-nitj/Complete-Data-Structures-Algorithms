//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        /*
        Idea 1: No water would be stored at corner towers, so start from index 1 and go till index n-2

        */
        long long water(0);
        /* for (int i = 1; i < n - 1; i++)
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
        } */
        // This method is almost same as the Naive Method but in this method we store the lheight and rheight beforehand.
        int lheight[n], rheight[n];
        lheight[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            lheight[i] = max(lheight[i - 1], arr[i]);
        }

        rheight[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rheight[i] = max(arr[i], rheight[i + 1]);
        }

        // lets add water
        for (int i = 0; i < n; i++)
        {
            water += (min(lheight[i], rheight[i]) - arr[i]);
        }

        return water;
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