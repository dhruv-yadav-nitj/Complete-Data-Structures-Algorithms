
// using parameterised recursion

#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define vp vector<vector<int>> 
using namespace std ;

void doSum (int i, int sum)
{
    if (i < 1)
    {
        cout << sum << endl ;
        return ; 
    }
    doSum(i-1, sum+i) ;
}

int main()
{
    int n ;
    cin >> n ;
    doSum (n, 0) ;

    return 0;
}