
// https://leetcode.com/problems/string-compression/

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        if (chars.size() < 2)
        {
            return chars.size();
        }
        string s;
        int  n = chars.size() ;
        for (int i = 0; i < n; )
        {
            int count =1 ;
            for (int j = i+1; j < n && (chars[i]==chars[j]); j++)
            {
                if (chars[i]==chars[j])
                {
                    count++ ;
                }
            }
            if (count==1)
            {
                s += chars[i] ;
                i++ ;
            }
            else
            {
                s += chars[i] ;
                s += to_string(count) ;
                i += count ;
            }
        }
        chars.clear() ;
        for (int i = 0; i < s.length(); i++)
        {
            chars.push_back(s[i]) ;
        }

        return chars.size() ;
    }
};