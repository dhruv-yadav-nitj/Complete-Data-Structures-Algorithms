#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define vp vector<vector<int>> 
using namespace std ;

int findLen (char arr[])
{
    int len= 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        len++ ;
    }
    return len ;
}

void reverseStr (char arr[], int size)
{
    int start = 0, end = size-1 ;
    while (start <= end)
    {
        swap(arr[start], arr[end]) ;
        start++, end-- ;
    }
}

int main()
{
    char arr[20] ;
    cin >> arr ;
    cout << arr << "\n" ;
    
    // run the code with input dhruv once and dhruv yadav once
    // char arrays stop the execution when there is a " " or '\0' or '\n'

    // calculating the length of the char array
    int size = findLen(arr) ;
    cout << size << "\n" ;

    // reverse print a char array
    for (int i = findLen(arr)-1; i >= 0; i--)
    {
        cout << arr[i] ;
    }
    cout << "\n" ;

    // reverse a char array permanently
    reverseStr (arr, size) ;
    cout << arr << "\n" ;
    
    return 0;
}