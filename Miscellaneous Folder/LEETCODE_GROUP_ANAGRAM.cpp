
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

// https://leetcode.com/problems/group-anagrams/

// COMPLETE BRUTE FORCE
// GOT TLE AS OBVIOUS
/* class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_set<string> s;
        for (auto &&i : strs)
        {
            string temp;
            temp = i;
            sort(temp.begin(), temp.end());
            s.insert(temp);
        }
        vector<vector<string>> ans;
        for (auto &&i : s)
        {
            vector<string> tempo;
            for (auto &&x : strs)
            {
                string sssss = x;
                sort(sssss.begin(), sssss.end());
                if (i == sssss)
                {
                    tempo.push_back(x);
                }
            }
            ans.push_back(tempo);
        }
        return ans;
    }
}; */

// Try 2
// Got Accepted
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (auto &&i : strs)
        {
            string temp = i;
            sort(temp.begin(), temp.end());
            m[temp].push_back(i);
        }
        vector<vector<string>> ans;
        for (auto &&i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};