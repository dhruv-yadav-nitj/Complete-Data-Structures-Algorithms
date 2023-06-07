#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

// Naive Solution
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};


// Efficient Solution #3
// Easy As Well
// Beats 95% in Time Complexity
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int smallest = matrix[0][0], largest = matrix[matrix.size() - 1][matrix[0].size() - 1];
        if (target < smallest or target > largest)
        {
            return false;
        }

        // set indexes for the top right element
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() and j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};


// Efficient Solution #1
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // Naive Solution
        /* int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j]==target)
                {
                    return true;
                }
            }
        }
        return false; */

        // Efficient Method
        int n = matrix.size(), m = matrix[0].size();
        /*
        Notes:
        1. Start from the top-right corner
        2. if the element == target then return the i, j
        3. if the element is less than target, then move to the next row
        4. if the element is greater than target, move to the left and search for the target in the same row
        */
        int requiredRow(0);
        while (requiredRow < n)
        {
            if (matrix[requiredRow][m - 1] == target)
            {
                return true;
            }
            else if (matrix[requiredRow][m - 1] < target)
            {
                requiredRow++;
            }
            else
            {
                break;
            }
        }
        if (requiredRow == n)
        {
            return false;
        }
        else
        {
            // apply binary search in that particular row

            int s = 0, e = m - 1;
            while (s < e)
            {
                int mid = s + (e - s) / 2;
                if (matrix[requiredRow][mid] == target)
                {
                    return true;
                }
                else if (matrix[requiredRow][mid] > target)
                {
                    e--;
                }
                else
                {
                    s++;
                }
            }
            return false;
        }
    }
};

// Efficient Solution #2
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0, end = rows * cols - 1, mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (matrix[mid / cols][mid % cols] == target)
            {
                return 1;
            }
            else if (matrix[mid / cols][mid % cols] < target)
            {
                start = mid + 1;
            }
            else if (matrix[mid / cols][mid % cols] > target)
            {
                end = mid - 1;
            }
        }

        return 0;
    }
};