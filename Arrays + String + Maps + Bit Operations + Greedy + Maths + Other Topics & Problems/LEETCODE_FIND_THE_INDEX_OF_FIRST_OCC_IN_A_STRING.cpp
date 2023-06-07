class Solution {
public:
    int strStr(string haystack, string needle)
    {
        // string::npos stands for the largest size of string data structure
        // https://www.geeksforgeeks.org/string-find-in-cpp/
        if(haystack.find(needle) != string::npos)
        {
            return haystack.find(needle);
        }
        else
        {
            return -1;
        }
    }
};