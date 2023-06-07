class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        string ans;
        ans = s;
        // when n > 1 then we can have the string sorted , took the example of S = "aacb" and k = 2, we can get aabc after some rotations
        if (k > 1)
        {
            sort(s.begin(), s.end());
            return (s);
        }
        else
        {
            // when k ==1 then we have to see the lexicographically smallest string of size of s in the string s+s
            // like if we have s= "cba" and k ==1 then s+s = "cbacba" then we have the answer acb, this is because we can have only 1 rotation at a time and that too of the first element and we can sent it back only which we can find using s+s
            string temp = "";
            temp = s + s;
            for (int i = 0; i + s.length() <= temp.length(); i++)
            {
                ans = min(ans, temp.substr(i, s.length()));
            }
            return ans;
        }
    }
};