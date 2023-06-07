#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define vp vector<vector<int>> 
using namespace std ;

string name = "dhruv" ;
int count = 0 ;

void print()
{
    if (::count==5)
    {
        return ;
    }
    cout << name << endl ;
    ::count++ ;
    print() ;
}

int main()
{
    print() ;

    return 0;
}