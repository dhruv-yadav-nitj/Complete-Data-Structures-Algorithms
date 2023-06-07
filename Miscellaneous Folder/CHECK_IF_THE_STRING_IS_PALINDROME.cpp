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

bool isValid(char sex)
{
    if ((sex >= 'a' and sex <= 'z') or (sex >= 'A' and sex <= 'Z') or (sex >= '0' and sex <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkPalindrome(string s)
{
    int st(0), e(s.length() - 1);
    while (st < e)
    {
        if (isValid(s[st]) == false)
        {
            st++;
        }
        else if (isValid(s[e]) == false)
        {
            e--;
        }
        else if (tolower(s[st]) != tolower(s[e]))
        {
            return false;
        }
        else
        {
            st++, e--;
        }
    }
    return true; 
}