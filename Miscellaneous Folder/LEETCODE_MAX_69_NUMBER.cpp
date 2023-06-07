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
    int maximum69Number(int num)
    {
        // we have to traverse from left to right in n and change the first occuring 6 to 9
        // we need not change any 9 to 6, because that would only make the number smaller
        int n = num;
        vector<int> temp;
        while (n > 0)
        {
            temp.push_back(n % 10);
            n /= 10;
        }
        reverse(temp.begin(), temp.end());
        for (auto &&i : temp)
        {
            if (i == 6)
            {
                i = 9;
                break;
            }
        }
        reverse(temp.begin(), temp.end());
        int mul = 1;
        int ans(0);
        for (auto &&i : temp)
        {
            ans += (i * mul);
            mul = mul * 10;
        }
        return ans;
    }
};