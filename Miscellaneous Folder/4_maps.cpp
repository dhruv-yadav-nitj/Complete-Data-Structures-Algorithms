
// maps are very useful in those CP problem in which we are asked to count frequency
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
using namespace std ;

int main()
{
    map <int, int> m ;
    
    cout << m.size() << endl ;

    // if an element is not present in a map, it will automatically assign it 0
    cout << m[15] << endl ;

    m[10] = 4 ;
    cout << m[10]  << endl ;

    cout << m.size() << endl ;

    map <int, int> freq ;

    // notice that initially the value of freq[10] is zero
    freq[10]++ ;
    freq[10]++ ;
    freq[10]++ ;
    freq[10]++ ;

    // now freq[10] would be 4
    cout << freq[10] << endl ;

    return 0;
}