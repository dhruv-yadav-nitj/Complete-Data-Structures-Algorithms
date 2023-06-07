
// print the maxm and minm element of an array
#include <iostream>
#include <cstdio>
using namespace std ;

int maxElement (int array[], int size)
{
    int maxm = 0;
    /*
    for (int i = 0; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i] ;
        }
    }
    */
    // stop using such bulky codes when we have predefined functions for the same work
    for (int i = 0; i < size; i++)
    {
        maxm = max(maxm, array[i]); // means ki maxm aur array[i] mein jo bada value hain usko maxm mein store kr do (similar for min function)
    }
    return maxm ;
}
int minElement (int array[], int size)
{
    int minm = array[0];
    for (int i = 1; i < size; i++)
    {
        minm = min(minm, array[i]) ;
        /*
        if (min < array[i])
        {
            continue;
        }
        else
        {
            min = array[i] ;
        }
        */
    }
    return minm ;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n ;
    int array[1000]; // its begin good practice to keep the size of an array constant
    for (int i = 0; i < n; i++)
    {
        cin >> array[i] ;
    }
    
    cout << "Max Element is: " << maxElement(array, n) << endl ;
    cout << "Min Element is: " << minElement(array, n) << endl ;

    return 0;
}