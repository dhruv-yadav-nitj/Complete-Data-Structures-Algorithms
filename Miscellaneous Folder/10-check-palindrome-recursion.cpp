#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define vp vector<vector<int>>
using namespace std;

bool checkPalindrom(string s, int i)
{
    if (i >= s.length()/2)
    {
        return true ;
    }
    if (s[i] == s[s.size()-i-1])
    {
        return checkPalindrom(s, i+1) ;
    }
    else
    {
        return false ;
    }
    
}

int main()
{
    string s;
    cin >> s;
    if (checkPalindrom(s, 0))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

// TC : O(s.size()/2)