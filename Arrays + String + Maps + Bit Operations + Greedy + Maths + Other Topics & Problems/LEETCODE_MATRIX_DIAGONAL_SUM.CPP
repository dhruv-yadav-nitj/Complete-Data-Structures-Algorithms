#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int ans(0), n(mat.size());
        for (int i = 0, j = n - 1; i < n and j >= 0; i++, j--)
        {
            // ans += mat[i][i];
            if (i == n / 2 and n % 2 == 1)
            {
                ans += mat[i][j];
            }
            else
            {
                ans += mat[i][j];
                ans += mat[i][i];
            }
        }
        return ans;
    }
};