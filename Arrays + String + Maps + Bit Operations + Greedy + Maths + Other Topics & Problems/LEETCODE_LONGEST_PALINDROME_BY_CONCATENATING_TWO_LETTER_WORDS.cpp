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
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> m;
        bool flag = true;
        for (auto &&i : words)
        {
            m[i]++;
        }
        int ans(0);
        for (int i = 0; i < words.size(); i++)
        {
            string rev = words[i];
            reverse(rev.begin(), rev.end());

            // Suppose we have words[] = {lc, cl, gg, hh, hh}
            // do hi cases ho skte hain ki agar kisi string ka reverse uske equal hoga ya nhi hoga since string are of len 2 only
            if (rev != words[i])
            {
                if (m[rev] > 0 and m[words[i]] > 0)
                {
                    ans += 4;
                    m[rev]--, m[words[i]]--;
                }
                // else to agar us string ka rev exist nhi krta hain words mein to uska koi kaam hi nahi hain
            }
            else
            {
                // means rev == words[i]
                if (m[words[i]] >= 2)
                {
                    ans += 4, m[words[i]] -= 2;
                }
                else if (m[words[i]] >= 1 and flag)
                {
                    ans += 2, m[words[i]]--;
                    flag = false;
                }
            }
        }
        return ans;
    }
};