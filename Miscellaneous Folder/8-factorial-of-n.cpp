
// using functional approach
// TC: O(n)
// SC: O(n)

#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define vp vector<vector<int>> 
using namespace std ;

l factorial(int n)
{
    if (n==1)
    {
        return 1 ;
    }
    return n * factorial(n-1) ;
}

int main()
{
    int n ;
    cin >> n ;
    cout << factorial(n) << endl ;

    return 0;
}