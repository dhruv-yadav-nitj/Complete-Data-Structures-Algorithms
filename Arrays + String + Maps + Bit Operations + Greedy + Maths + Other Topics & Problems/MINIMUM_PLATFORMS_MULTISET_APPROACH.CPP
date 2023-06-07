//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // we would be using a multiset here
        multiset<pair<int, char>> m;
        for (int i = 0; i < n; i++)
        {
            m.insert(make_pair(arr[i], 'a'));
            m.insert(make_pair(dep[i], 'd'));
            // we are inserting the elements of both the arrays in a multiset so that they are in sorted order and assigning a to the arrival elements and d to the dep elements
        }
        int curr(0), maxi(0);
        for (auto &&i : m)
        {
            if (i.second == 'a')
            {
                curr++;
            }
            else if (i.second == 'd')
            {
                curr--;
            }
            maxi = max(maxi, curr);
        }
        return maxi;
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
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
}
// } Driver Code Ends