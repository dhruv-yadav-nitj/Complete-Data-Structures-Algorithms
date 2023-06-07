#include <bits/stdc++.h>
using namespace std ;

void doSort (int arr[], int n)
{
    int min_idx ;
    for (int i = 0; i < n-1; i++)
    {
        min_idx = i ;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[min_idx])
            {
                min_idx = j ;
            }
        }
        
        swap(arr[min_idx], arr[i]) ;
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n" ;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11} ;
    int n = sizeof(arr)/sizeof(int) ;
    cout << "Prev Arr: " ;
    printArr(arr, n) ;

    doSort(arr, n) ;
    cout << "Sorted Arr: " ;
    printArr(arr, n) ;

    return 0;
}