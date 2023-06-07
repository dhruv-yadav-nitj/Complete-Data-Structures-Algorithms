// https://leetcode.com/problems/reverse-words-in-a-string/description/
// A very good Solution it was

#include <bits/stdc++.h>
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
    string reverseWords(string s)
    {
        string ans;
        int i(0);
        while (i < s.length())
        {
            if (s[i] == ' ')
            {
                i++;
            }
            else
            {
                string temp;
                while (i < s.length() and s[i] != ' ')
                {
                    temp += s[i];
                }
                if (ans.length() == 0)
                {
                    ans += temp;
                }
                else
                {
                    // this thing would work as reversing of the string
                    ans = temp + ' ' + ans;
                }
            }
        }
        return ans;
    }
};

// Method 2
// POTD - 13-11-2022
/*
#include <bits/stdc++.h>
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
    string reverseWords(string s)
    {
        int low(0), high(s.length() - 1);
        while (s[low] == ' ')
        {
            low++;
        }
        while (s[high] == ' ')
        {
            high--;
        }

        // now since we have remove the extra space before and after the main string, we have reduced our work space
        string temp = "";
        vector<string> ans;
        string res;
        while (low <= high)
        {
            if (s[low] == ' ' or low == high)
            {
                ans.push_back(temp);
                temp = "";
                while (s[low] == ' ' and low <= high)
                {
                    low++;
                }
            }
            else
            {
                temp += s[low++];
            }
        }
        reverse(ans.begin(), ans.end());
        for (auto &&i : ans)
        {
            res += i;
        }
        res.pop_back();
        return res;
    }
};
*/