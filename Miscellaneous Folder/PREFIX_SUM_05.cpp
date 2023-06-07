
// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
// Check if there is a subarray with 0 sum

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
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            // if we found the sum in map or if sum ==0 then return true else increase the frequency of the sum in map with +1.what
            // m.find(x) returns m.end() when x is not found in m. So m.find(x) != m.end() means x found in map m
            // m[sum] >= 1 means sum is already present in the map m
            // let say we have some sum = x and we do m[x]++ and after some iterations we found m[x]>=1 this means that x was already present in map m. This means that x + y = x viz. we have found some subarray with sum y which is zero.
            if (m[sum] >= 1 or sum == 0)
            {
                return true;
            }
            else
            {
                m[sum]++;
            }
        }
        return false ;
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