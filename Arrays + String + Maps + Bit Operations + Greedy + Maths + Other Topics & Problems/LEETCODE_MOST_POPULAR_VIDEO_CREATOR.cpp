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
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        unordered_map<string, int> m;
        map<string, vector<pair<string, int>>> m2;
        int maxi(INT_MIN);

        for (int i = 0; i < creators.size(); i++)
        {
            m[creators[i]] += views[i];
            maxi = max(maxi, m[creators[i]]);
            m2[creators[i]].push_back(make_pair(ids[i], views[i]));
        }
        vector<vector<string>> ans;
        for (auto &&i : m)
        {
            if (i.second == maxi)
            {
                vector<string> individualAns;
                string artist = i.first;
                individualAns.push_back(artist);
                string temp = m2[i.first][0].first;
                int q = m2[i.first][0].second;
                for (auto &&z : m2[i.first])
                {
                    if (z.second > q)
                    {
                        temp = z.first;
                        q = z.second;
                    }
                    else if (z.second == q and temp > z.first)
                    {
                        temp = z.first;
                    }
                }
                individualAns.push_back(temp);
                ans.push_back(individualAns);
            }
        }
        return ans;
    }
};