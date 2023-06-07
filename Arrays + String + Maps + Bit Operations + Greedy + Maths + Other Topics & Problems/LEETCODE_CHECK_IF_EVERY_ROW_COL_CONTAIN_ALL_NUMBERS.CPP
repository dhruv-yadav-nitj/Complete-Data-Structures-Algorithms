#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValid(vector<vector<int>> &matrix)
    {

        // checking row wise
        for (int i = 0; i < matrix.size(); i++)
        {
            unordered_set<int> s;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                s.insert(matrix[i][j]);
            }
            if (s.size() < matrix[i].size())
            {
                return false;
            }
        }

        // checking column wise
        int n = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> s;
            for (int j = 0; j < n; j++)
            {
                s.insert(matrix[j][i]);
            }
            if (s.size() < n)
            {
                return false;
            }
        }

        return true;
    }
};