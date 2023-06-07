// https://leetcode.com/problems/spiral-matrix-iii/
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
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        int total(rows * cols), count(1);
        int i(1), j(2);
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        map<vector<int>, int> m;
        while (count < total)
        {
            // agar jo coordinates hain wo matrix k andar lie kr rhe hain to count++ kro
            // start with i = 1, j = 1 (increase in row and col)

            // increaseing in cols
            for (int temp = 0; temp < i; temp++)
            {
                cStart++;
                if (rStart < rows and cStart < cols and rStart >= 0 and cStart >= 0 and count <= total and m.count({rStart, cStart}) == 0)
                {
                    ans.push_back({rStart, cStart});
                    m[{rStart, cStart}]++;
                    count++;
                }
            }
            // increasing in rows
            for (int temp = 0; temp < i; temp++)
            {
                rStart++;
                if (rStart < rows and cStart < cols and rStart >= 0 and cStart >= 0 and count <= total and m.count({rStart, cStart}) == 0)
                {
                    ans.push_back({rStart, cStart});
                    m[{rStart, cStart}]++;
                    count++;
                }
            }

            // decrease in cols
            for (int temp = 0; temp < j; temp++)
            {
                cStart--;
                if (rStart < rows and cStart < cols and rStart >= 0 and cStart >= 0 and count <= total and m.count({rStart, cStart}) == 0)
                {
                    ans.push_back({rStart, cStart});
                    m[{rStart, cStart}]++;
                    count++;
                }
            }

            // decrease in rows
            for (int temp = 0; temp < j; temp++)
            {
                rStart--;
                if (rStart < rows and cStart < cols and rStart >= 0 and cStart >= 0 and count <= total and m.count({rStart, cStart}) == 0)
                {
                    ans.push_back({rStart, cStart});
                    m[{rStart, cStart}]++;
                    count++;
                }
            }

            i += 2, j += 2;
        }
        return ans;
    }
};
