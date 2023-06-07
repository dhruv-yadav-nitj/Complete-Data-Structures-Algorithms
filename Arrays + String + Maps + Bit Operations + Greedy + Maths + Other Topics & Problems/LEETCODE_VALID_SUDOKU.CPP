#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // traverse to hme 9x9 times krna hi pdhega
        unordered_set<string> s;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    string box = "box", row = "row", col = "col";
                    row += to_string(i) + (board[i][j]);
                    col += to_string(j) + (board[i][j]);
                    box += to_string((i / 3 * 3) + (j / 3)) + (board[i][j]);

                    if (s.count(row) == 1 or s.count(col) == 1 or s.count(box))
                    {
                        return false;
                    }
                    s.insert(box);
                    s.insert(row);
                    s.insert(col);
                }
            }
        }
        return true;
    }
};