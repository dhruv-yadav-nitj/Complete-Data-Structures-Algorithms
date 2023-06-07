class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int size = s.size() - 1;
        int start = 0, end = size;
        while (start <= end)
        {
            swap(s[start], s[end]);
            start++, end--;
        }
    }
};