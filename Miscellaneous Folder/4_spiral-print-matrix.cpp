
// https://leetcode.com/problems/spiral-matrix/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0, total = row * col;
        int startingRow = 0, startingCol = 0, endingRow = row - 1, endingCol = col - 1;

        while (count < total)
        {

            // printing starting row
            for (int i = startingCol; i <= endingCol && count < total; i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // printing ending Column
            for (int i = startingRow; i <= endingRow && count < total; i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            // printing ending Row
            for (int i = endingCol; i >= startingCol && count < total; i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // printing starting Column
            for (int i = endingRow; i >= startingRow && count < total; i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};