//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // The trick to solve this type of problem is to first find the Transpose of the Matrix. Then do the swapping as per the ques demands.
    // Refer to the LeetCode Ques #48 Rotate Image
    void rotateMatrix(vector<vector<int>> &arr, int n)
    {
        // Transpose --> Swap Row Elements
        // first step is to find the transpose
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i; j < arr[i].size(); j++)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }

        // after the above step we have tranposed matrix, now we have to swap individual row elements
        for (int i = 0; i < arr.size() / 2; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                swap(arr[i][j], arr[arr.size() - 1 - i][j]);
            }
        }
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
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            vector<int> a;
            for (int j = 0; j < n; j++)
            {
                cin >> x;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        Solution ob;
        ob.rotateMatrix(arr, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends