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

// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        unordered_map<char, int> m1, m2;
        for (int i = 0; i < p.length(); i++)
        {
            m1[s[i]]++;
            m2[p[i]]++;
        }
        if (m1 == m2)
        {
            ans.push_back(0);
        }
        for (int i = p.length(); i < s.length(); i++)
        {
            m1[s[i - p.length()]]--;
            if (m1[s[i - p.length()]] == 0)
            {
                m1.erase(m1.find(s[i - p.length()]));
            }
            m1[s[i]]++;
            if (m1 == m2)
            {
                ans.push_back(i - p.length() + 1);
            }
        }
        return ans;
    }
};