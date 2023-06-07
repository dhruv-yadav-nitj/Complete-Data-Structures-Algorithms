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

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int count(1), total(n * n);
        int top(0), bottom(n - 1), left(0), right(n - 1);
        vector<vector<int>> ans(n, vector<int>(n));
        while (count <= total)
        {
            // we would approach the matrix as we did in Spiral Matrix 01 Problem
            // printing the top row
            for (int j = left; j <= right and count <= total; j++)
            {
                ans[top][j] = count++;
            }
            top++;

            // printing the right column
            for (int i = top; i <= bottom and count <= total; i++)
            {
                ans[i][right] = count++;
            }
            right--;

            // printing the bottom row
            for (int j = right; j >= left and count <= total; j--)
            {
                ans[bottom][j] = count++;
            }
            bottom--;

            // printing the left most column
            for (int i = bottom; i >= top and count <= total; i--)
            {
                ans[i][left] = count++;
            }
            left++;
        }
        return ans;
    }
};