#include <bits/stdc++.h>
using namespace std ;

int main()
{
    vector <int> v ;
    v.push_back(1) ;
    v.push_back(3) ;
    v.push_back(6) ;
    v.push_back(9) ;

    cout << "Is 6 present ? " << binary_search(v.begin(), v.end(), 6) << endl; 

    int a = 5, b= 6;
    cout << max(a,b) << endl ;
    cout << min(a,b) << endl ;
    swap(a, b) ;
    cout << a << " " << b << endl ;

    string s = "abcd" ;
    reverse (s.begin(), s.end()) ;
    cout << s << endl ;

    rotate(v.begin(), v.begin()+1 , v.end()) ; // begin()+1 for the element jiske about rotate krna hain
    cout << "After rotate: \n"  ;
    for (int i :v)
    {
        cout << i << " " ;
    }cout << endl ;

    // we also have sort function , refer to Sorting folder

    return 0;
}