#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define vp vector<vector<int>> 
using namespace std ;

char returnMax (string s)
{
    int count= 1, temp= INT_MIN;
    char ans ;
    for (int i = 0; i < s.size()-1; i++)
    {
        count =1;
        for (int j = i+1; j < s.size(); j++)
        {
            if (s[i]==s[j])
            {
                count++ ;
            }
        }
        if (count > temp)
        {
            ans = s[i] ;
        }
        temp = max(temp, count) ;
    }
    return ans ;
}

int main()
{
    string s ;
    cin >> s ;
    sort(s.begin(), s.end()) ;
    cout << returnMax(s) << endl ;

    return 0;
}