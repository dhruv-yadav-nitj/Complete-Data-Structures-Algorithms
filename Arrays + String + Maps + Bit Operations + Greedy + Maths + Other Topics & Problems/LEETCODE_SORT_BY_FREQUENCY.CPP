#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool custom(const pair<char, int> a, const pair<char, int> b)
    {
        return a.second > b.second;
    }
    string frequencySort(string s)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }

        vector<pair<char, int>> v;
        for (auto &&i : m)
        {
            v.push_back(make_pair(i.first, i.second));
        }

        sort(v.begin(), v.end(), custom);

        string ans;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].second; j++)
            {
                ans += v[i].first;
            }
        }
        return ans;
    }
};