class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        map<char, int> m;
        int i(0), counter(0), count(0), ans(0);
        while (counter < n)
        {
            if (m[s[i]] >= 1 or i == n)
            {
                ans = max(ans, count);
                count = 0;
                m.clear();
                i = counter;
                counter++;
            }
            else
            {
                m[s[i]]++, count++;
            }
            i++;
        }
        return ans;
    }
};