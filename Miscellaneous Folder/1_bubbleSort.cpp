#include <bits/stdc++.h>
using namespace std ;

void printArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << "\n" ;
}

void bubbleSort (int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        // to make code optimised
        bool ifSwapped = false ;
        for (int j = 0; j < (n-1)-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]) ;
                ifSwapped = true;
            }
        }
        // if swapped is false means nothing is swapped means the array is already sorted, with this method we can save time by judging whether the array is sorted or not just iterating the first round, otherwise the code would iterate through all the elements as in prev code
        if (ifSwapped = false)
        {
            break ;
        }
        
    }
}


int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    bubbleSort(arr, n) ;
    cout << "Sorted Array: " ; 
    printArray(arr, n) ;

    return 0;
}