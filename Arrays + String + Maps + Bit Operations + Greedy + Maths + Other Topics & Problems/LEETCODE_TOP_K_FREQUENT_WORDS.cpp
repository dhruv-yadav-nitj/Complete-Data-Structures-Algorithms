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
    static bool customSort(pair<string, int> &a, pair<string, int> &b)
    {
        if (a.second == b.second)
        {
            // in this case sort alphabetically
            // Since it is given in the ques
            // Sort the words with the same frequency by their lexicographical order.
            return a.first < b.first;
        }
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        // map<key, value> m
        map<string, int> m;
        for (auto x : words)
        {
            m[x]++;
        }
        vector<pair<string, int>> v;
        for (auto &it : m)
        {
            v.push_back({it.first, it.second});
        }
        // sort(v.begin(), v.end());
        // now we have to sort the vector in the decreasing order of the values
        sort(v.begin(), v.end(), customSort);
        vector<string> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};

int main()
{
    IOS;

    return 0;
}