class Solution
{
public:
    bool isPalindrome(string s)
    {
        string s1;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 65 && s[i] <= 90) || s[i] >= 97 && s[i] <= 122 || s[i] >= 48 && s[i]<= 57)
            {
                s1 += s[i];
            }
        }
        string v;
        for (int i = 0; i < s1.size(); i++)
        {
            v += tolower(s1[i]);
        }
        int start = 0, end = v.size() - 1;
        while (start <= end)
        {
            if (v[start] == v[end])
            {
                start++, end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};