#include <bits/stdc++.h>
using namespace std ;

int main()
{
    // Problem Statement : Given an array which consist of only 0's and 1's. Sort the array such that all the 0's lie in the left side and all the 1's lie in the right side.
    // we have 3 different approaches to solve this problem :
    // Counting (or) Sorting (or) Two Pointer Approach
    /*
    In Counting, Count number of 0's and 1's, and make a new array with such number of 0's and 1's with all 0's at left and all 1's starting after such number of 0's. Brute Force method it is, havind more TC so dont apply that.

    In Sorting we would use sort function present in C++ STL. this method have TC 0(nlogn), n is the number of elements;

    In Two Pointer Approach, we would two pointers (this method is applied in 56_sort0_1.cpp)
    */

    // In this program we have used, sort function

    int array[100] ;
    int n;
    cin >> n ;
    // Enter elements of array
    for (int i = 0; i < n; i++)
    {
        cin >> array[i] ;
    }
    sort (array, array+(n-1)) ;
    // we can also use the function in this way for both array and strings
    // sort(wrong.begin(), wrong.end()) ;

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl ;

    return 0;
}