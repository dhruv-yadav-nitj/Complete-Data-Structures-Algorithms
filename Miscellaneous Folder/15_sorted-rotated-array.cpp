
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

bool check(vector<int> &nums)
{
    // flag to keep count of pairs in which nums[i] > nums[i+1]
    int flag = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {

        // first pair found so make flag = 1
        if (nums[i] > nums[i + 1] && flag == 0)
        {
            flag = 1;
        }

        // if there exists another pair where nums[i] > nums[i+1], so array is not rotated and sorted
        // return false
        else if (nums[i] > nums[i + 1] && flag == 1)
        {
            return false;
        }
    }

    // check for last and first element using same logic
    if (nums[nums.size() - 1] > nums[0] && flag == 1)
    {
        return false;
    }

    return true;
}