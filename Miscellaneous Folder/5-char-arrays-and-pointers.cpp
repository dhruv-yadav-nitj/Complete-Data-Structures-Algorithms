#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
using namespace std ;

int main()
{
    int arr[] = {4, 5, 6} ;
    int *ptrTemp = &arr[0] ;
    cout << ptrTemp << endl ;

    // always keep sizeof a char arr = 1 + no. of elements
    char arr1[5] = {'x', 'r', 's', 't'} ;
    cout << arr << " " << arr1 << endl ;
    // see the difference b/w the implementation of an int arr and a char arr

    char *ptr = &arr1[0] ;
    cout << ptr << " " << *ptr << endl ;
    // ptr would print the whole arr

    char temp = 'a' ;
    char *ptr1 = &temp ;
    cout << ptr1 << endl ;
    // here also the same thing ptr would print until it gets some null character
    
    return 0;
}