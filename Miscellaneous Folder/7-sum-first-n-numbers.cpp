
// using functional approach

#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define vp vector<vector<int>> 
using namespace std ;

int printSum (int n)
{
    // making base condition
    if (n==0)
    {
        return 0 ;
    }
    return n + printSum(n-1) ;    
}

int main()
{
    int n;
    cin >> n ;
    cout << printSum(n) << endl ;

    return 0;
}