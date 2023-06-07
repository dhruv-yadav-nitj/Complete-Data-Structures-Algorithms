
// https://leetcode.com/problems/search-a-2d-matrix/
// TC = O(log(row*col))

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0, end = rows * cols - 1, mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (matrix[mid / cols][mid % cols] == target)
            {
                return 1;
            }
            else if (matrix[mid / cols][mid % cols] < target)
            {
                start = mid + 1;
            }
            else if (matrix[mid / cols][mid % cols] > target)
            {
                end = mid - 1;
            }
        }

        return 0;
    }
};