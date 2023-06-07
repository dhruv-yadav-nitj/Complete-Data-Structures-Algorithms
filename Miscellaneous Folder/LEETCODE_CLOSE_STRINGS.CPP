#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {

        // first check for size of the strings
        if (word1.size() != word2.size())
        {
            return false;
        }

        unordered_set<char> s1, s2;

        unordered_map<char, int> m1, m2;

        unordered_set<int> p1, p2;

        for (int i = 0; i < word1.size(); i++)
        {
            m1[word1[i]]++;
            m2[word2[i]]++;
            s1.insert(word1[i]);
            s2.insert(word2[i]);
        }

        for (auto &&i : s1)
        {
            if (s2.count(i) == 0)
            {
                return false;
            }
        }

        int count1(0), count2(0);

        vector<int> st1, st2;
        for (auto &&i : m1)
        {
            st1.push_back(i.second);
        }

        for (auto &&i : m2)
        {
            st2.push_back(i.second);
        }

        sort(st1.begin(), st1.end());
        sort(st2.begin(), st2.end());

        if (st1.size() != st2.size())
        {
            return false;
        }

        for (int i = 0; i < st1.size(); i++)
        {
            if (st1[i] != st2[i])
            {
                return false;
            }
        }

        return true;
    }
};