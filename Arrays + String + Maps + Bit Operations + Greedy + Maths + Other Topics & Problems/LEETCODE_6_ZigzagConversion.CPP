/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
#include <bits/stdc++.h>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        // code here
        vector<string> temp(numRows, "");

        int m = s.size();
        int a = 0;
        int k = 0;
        int j = 0;
        int n = numRows;
        while (a < m)
        {

            if (k & 1)
            {

                for (int i = n - 2; i >= 1 && j < m; i--)
                {
                    /* code */

                    temp[i].push_back(s[j]);
                    j++;
                    a++;
                }
            }
            else
            {

                for (int i = 0; i < numRows && j < m; i++)
                {

                    temp[i].push_back(s[j]);
                    j++;
                    a++;
                }
            }
            k++;

            // a = j;
        }

        string ans = "";

        for (int i = 0; i < temp.size(); i++)
        {

            for (int j = 0; j < temp[i].size(); j++)
            {

                ans += temp[i][j];
            }
        }

        return ans;
    }
};
// @lc code=end
