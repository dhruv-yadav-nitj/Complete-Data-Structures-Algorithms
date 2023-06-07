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
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size() - 1; j++)
            {
                if (matrix[i][j] != matrix[i + 1][j + 1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};