
// Status: Runtime Error

#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define vp vector<vector<int>> 
using namespace std ;

vl v ;
bool isPrime (l n)
{
    for (l i = 2; i*i <= n; i++)
    {
        if (n%i == 0)
        {
            return false ;
        }
    }
    return true ;
}

void storePrime ()
{
    v.push_back(2) ;
    v.push_back(3) ;
    for (l i = 4; i <= 5000000; i++)
    {
        if (isPrime(i))
        {
            v.push_back(i) ;
        }
    }
}

int main()
{
    l q ;
    cin >> q ;
    while (q--)
    {
        l n ;
        cin >> n ;
        cout << v[n-1] << endl ;
    }
    

    return 0;
}