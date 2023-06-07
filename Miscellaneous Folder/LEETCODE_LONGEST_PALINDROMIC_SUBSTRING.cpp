#include <bits/stdc++.h>
#include <string.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != s[s.length() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        int n = s.length();
        string ans = "";
        ans = s[0];
        for (int i = 0; i < s.length(); i++)
        {
            int j = n - 1;
            while (j > i)
            {
                if (s[i] == s[j])
                {
                    string temp = "";
                    temp = s.substr(i, (j - i + 1));
                    if (isPalindrome(temp))
                    {
                        if (ans.length() < temp.length())
                        {
                            ans = temp;
                        }
                        break;
                    }
                }
                j--;
            }
        }
        return ans;
    }
};

int main()
{
    IOS;
    return 0;
}