//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        if (n == 0)
            return -1;

        int smallest = matrix[0][0], largest = matrix[n - 1][n - 1];
        if (x < smallest || x > largest)
            return -1;

        // set indexes for top right element
        int i = 0, j = n - 1;
        while (i < n && j >= 0)
        {
            if (matrix[i][j] == x)
            {
                return 1;
            }
            if (matrix[i][j] > x)
                j--;

            // Check if mat[i][j] < x
            else
                i++;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.search(matrix, n, m, x))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

// } Driver Code Ends