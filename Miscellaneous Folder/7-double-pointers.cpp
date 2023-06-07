#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
using namespace std ;

int main()
{
    int var = 10 ;
    int* ptr = &var ;
    int ** ptr2 = &ptr ;

    cout << var << " " << *ptr << " " << *ptr2 << " " << **ptr2 << endl ;

    return 0;
}