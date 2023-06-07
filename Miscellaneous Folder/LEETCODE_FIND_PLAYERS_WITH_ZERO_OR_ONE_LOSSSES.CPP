#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {

        // How Noobs Code -->

        /* vector<int> oneTimeLosers, ajay;
        vector<vector<int>> ans;
        unordered_map<int, int> losers;
        unordered_set<int> players;
        for (int i = 0; i < matches.size(); i++)
        {
            losers[matches[i][1]]++;
            for (int j = 0; j < 2; j++)
            {
                players.insert(matches[i][j]);
            }
        }
        for (auto &&i : losers)
        {
            if (i.second == 1)
            {
                oneTimeLosers.push_back(i.first);
            }
        }
        sort(oneTimeLosers.begin(), oneTimeLosers.end());
        for (auto &&i : players)
        {
            if (losers.count(i) == 0)
            {
                ajay.push_back(i);
            }
        }
        sort(ajay.begin(), ajay.end());
        ans.push_back(ajay), ans.push_back(oneTimeLosers);
        return ans; */

        // How Pros Code -->
        // we cant use unordered_map, since its not sorted.
        map<int, int> m;
        vector<int> zeros, ones;
        for (auto &&i : matches)
        {
            if (!m.count(i[0]))
                m[i[0]] = 0;
            m[i[1]]++;
        }
        for (auto &&i : m)
        {
            if (i.second == 0)
                zeros.push_back(i.first);
            if (i.second == 1)
                ones.push_back(i.first);
        }
        return {zeros, ones};
    }
};