
// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int startRow = 0;
        int startCol = col - 1;

        while (startCol >= 0 && startRow < row)
        {
            int element = matrix[startRow][startCol];

            if (element == target)
            {
                return 1;
            }
            else if (element < target)
            {
                startRow++;
            }
            else if (element > target)
            {
                startCol--;
            }
        }
        return 0;
    }
};