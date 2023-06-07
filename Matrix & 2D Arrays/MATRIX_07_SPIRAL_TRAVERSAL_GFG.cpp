//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        vector<int> ans;
        int top(0), left(0), right(matrix[0].size() - 1), bottom(matrix.size() - 1);
        // what we have to do is to change the above declared variables after every iteration
        // we have to increase the startTop++ , startLeft--, startRight++, startBottom--
        int rowNum(matrix.size()), colNum(matrix[0].size());

        // count is the number of elements printed till now and total is the total number of elements present in the matrix
        int count(0), total(rowNum * colNum);
        while (count < total)
        {
            // lets print the top most row of the present matrix
            for (int j = left; j <= right and count < total; j++)
            {
                ans.push_back(matrix[top][j]);
                count++;
            }top++;

            // lets print the right most columns of the present matrix
            for (int i = top; i <= bottom and count < total; i++)
            {
                ans.push_back(matrix[i][right]);
                count++;
            }right--;

            // lets print the bottom most row of the present matrix
            for (int j = right; j >= left and count < total; j--)
            {
                ans.push_back(matrix[bottom][j]);
                count++;
            }bottom--;

            // lets print the left most column of the present matrix
            for (int i = bottom; i >= top and count < total; i--)
            {
                ans.push_back(matrix[i][left]);
                count++;
            }left++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends