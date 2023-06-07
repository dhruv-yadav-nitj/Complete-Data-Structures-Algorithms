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

        // we are having a very good and clear multiset approach for this problem.. refer that
        sort(arr, arr + n);
        sort(dep, dep + n);
        int i(1), j(0);
        // i would keep the track of arrival arr and j would keep the track of departure array
        int curr(1), maxi(1);
        while (i < n)
        {
            if (arr[i] <= dep[j])
            {
                // iska mtlb ki abhit k ek train gya nhi but dusra chala aaya, tb hme count++ krna hoga
                curr++;
                i++;
            }
            else
            {
                curr--;
                j++;
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