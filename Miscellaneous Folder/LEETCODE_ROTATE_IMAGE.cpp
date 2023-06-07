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
    void rotate(vector<vector<int>> &matrix)
    {
        // first find the transpose of the matrix
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i; j < matrix[i].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // now swap the elements as per the rotation requirements
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size() / 2; j++)
            {
                swap(matrix[i][j], matrix[i][matrix[i].size() - 1 - j]);
            }
        }
    }
};