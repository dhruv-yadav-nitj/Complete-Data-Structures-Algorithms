#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

void say_hello (int i, int n)
{
    if (i==n)
    {
        return ;
    }
    cout << "hello " << i+1 << endl ;
    say_hello(++i, n) ;
}

int main()
{
    IOS;
    int n ; cin >> n ;
    say_hello(0, n) ;

    return 0;
}