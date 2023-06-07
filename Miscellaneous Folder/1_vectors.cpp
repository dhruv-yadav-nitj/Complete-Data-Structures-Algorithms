#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define vp vector<vector<int>> 
using namespace std ;

int main()
{
    // how to initialise a vector with customized dafault value
    vector<int> v(10, 100) ;
    for (auto x: v)
    {
        cout << x << endl ;
    }
    
    // remove the last element
    v.pop_back() ;

    // insert an element at the end
    v.push_back(20) ;

    // for size of the vector
    cout << v.size()  << endl ;

    // sort ; its a mix of three sorting algos , merge sort, quick sort and heap sort and its TC is   O(nlogn) , so when to sort an array or vector its better to use sort
    int arr[] = {12, 342, 12 , 65, 121, 90} ;
    sort (arr, arr+6) ;
    for (auto x : arr)
    {
        cout << x << " " ;
    }
    cout << endl ;

    

    return 0;
}