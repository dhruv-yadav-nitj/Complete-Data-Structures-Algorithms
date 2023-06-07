#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
using namespace std ;

int main()
{
    // set is something which stores only unique elements
    // random access is not allowed in Sets
    set <int> s ;
    s.insert (10) ;
    s.insert (10) ;
    s.insert (10) ;

    // does not matter how many times an element is inserted in a set, it would be stored only once
    // elements are automatically stored in sorted order in a set
    // we can access the elements in a set only using iterators

    s.insert(15) ;
    s.insert(11) ;

    // erase function
    s.erase (11) ;

    // s.count returns 0 or 1, it is used to check whether a elements in preent in a set or not
    cout << s.count(15) << endl ;

    // to access the elements in a set we use iterators
    cout << *s.begin() << endl ;
   

    return 0;
}