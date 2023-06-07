
// https://drive.google.com/drive/folders/1HKRJWoeKDl0jnX6QmrKdFX0D8zsDzBYU?usp=sharing

#include <bits/stdc++.h>
#define l long long
using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    vector <int> denom ;
    int a ;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        denom.push_back(a) ;
    }
    sort (denom.begin(), denom.end(), greater<int>()) ;
    int amount;
    cin >> amount ;
    int count =0 ;

    for (int i = 0; i < n; i++)
    {
        count += amount / denom[i] ;
        amount -= (amount/denom[i]) * denom[i] ;
    }
    cout << count <<endl ;

    return 0;
}