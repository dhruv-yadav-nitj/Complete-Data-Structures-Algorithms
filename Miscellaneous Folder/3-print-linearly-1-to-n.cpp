#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define vp vector<vector<int>> 
using namespace std ;

int n ;
int i = 1 ;

void print()
{
    if (i > n)
    {
        return ;
    }
    cout << i << endl ;
    i++ ;
    print() ;    
}

int main()
{
    cin >> ::n ;
    print() ;   

    return 0;
}