
#include <bits/stdc++.h>
using namespace std ;

int findPivot (int array[], int n)
{
    int s = 0 , e = n-1 ;
    while (s < e)
    {
        int mid = s + (e-s)/2 ;
        if (array[mid]>=array[0])
        {
            s = mid+1 ;
        }
        else 
        {
            e = mid ;
        }
    }
    return s ; // the index of the pivot element
}

int binarySearch (int array[], int s , int e, int key)
{
    int start = s, end = e;
    while (start<=end)
    {
        int mid = start + (end-start)/2 ;
        if (array[mid]==key)
        {
            return mid ;
        }
        else if (array[mid]>key)
        {
            end = mid-1 ;
        }
        else if (array[mid]<key)
        {
            start = mid+1 ;
        }
        
    }
    return -1 ;
}

int main()
{
    int array[] = {7, 8, 1, 3, 5} ;
    int pivot = findPivot(array, sizeof(array)/sizeof(int)) ;
    cout << pivot << endl ;
    int key ;
    cin >> key ;
    int n = sizeof(array)/sizeof(int) ;
    // now if target lies b/w pivot element and end then we need to search in the second line and else in the first line, keep in mind we always know the 1st and last element of an array and here we have also founded the pivot element, so we would be using those things

    if (key >= array[pivot] && key <= array[n-1])
    {
        cout << "Element found at :" << binarySearch (array, pivot, n-1, key) << endl ;
    }
    else
    {
        cout << "Element found at : " << binarySearch (array, 0 , pivot-1, key) << endl ;
    }
    
    return 0;
}