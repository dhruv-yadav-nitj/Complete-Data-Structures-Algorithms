
// Naive Solution
// Approach: First insert all the elements of the matrix in a temp vector and then sort the vector temp. Find the middle element of the temp.
/* class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // Given R and C are total no. of rows and columns respectively
        vector<int> temp;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                temp.push_back(matrix[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        return temp[temp.size() / 2];
    }
}; */

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // given R and C are total no. of rows and columns respectively
        /*
        Notes:
        0. Idea is that a number to be median there should be exactly (n/2) numbers smaller than that number in that data structure.
        1. Find the min and max of all the elements in the matrix, min element can be found by comparing the first element of all the rows and max element can be found by comparing the last element of all the rows.
        2.
        */
        // since we have R as number of Rows and C as number of Columns
        int mini = matrix[0][0], maxi = matrix[0][C - 1];
        for (int i = 1; i < R; i++)
        {
            mini = min(mini, matrix[i][0]);
            maxi = max(maxi, matrix[i][C - 1]);
        }
        // Article on how upper_bound works
        // https://www.geeksforgeeks.org/upper_bound-in-cpp/#:~:text=upper_bound()%20is%20a%20standard,no%20such%20element%20is%20found.

        int temp = (R * C + 1) / 2;
        // temp denotes the number which are required to be smaller than the current mid to be able to mid to be median
        while (mini < maxi)
        {
            int mid = mini + (maxi - mini) / 2;
            int count(0);
            for (int i = 0; i < R; i++)
            {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                // upper_bound() is a standard library function in C++ defined in the header . It returns an iterator pointing to the first element in the range [first, last] that is greater than value, or last if no such element is found. The elements in the range shall already be sorted or at least partitioned with respect to val. 
            }
            if (count < temp)
            {
                mini = mid + 1;
            }
            else
            {
                maxi = mid - 1;
            }
        }
        return mini;
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
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
}
// } Driver Code Ends