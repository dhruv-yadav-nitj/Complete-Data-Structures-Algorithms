//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void LeftRotateAnArray(int arr[], int n)
    {
        int temp = arr[0];
        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        ob.LeftRotateAnArray(arr, n);
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends