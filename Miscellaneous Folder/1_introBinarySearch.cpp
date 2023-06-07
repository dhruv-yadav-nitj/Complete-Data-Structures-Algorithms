#include <bits/stdc++.h>
using namespace std ;

int binarySearch(int array[], int n, int key)
{
    int s = 0, e = n-1 ;
    while (s<=e)
    {
        int mid = s + (e-s)/2 ;
        if (array[mid] == key)
        {
            return mid ;
        }
        else if (array[mid] < key)
        {
            s = mid+1 ;
        }
        else if (array[mid] > key)
        {
            e = mid-1 ;
        }
    }
    return -1 ;

}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    int key ;
    cin >> key ;
    cout << "Element found at index: " << binarySearch(array, sizeof(array)/sizeof(int), key) << endl ;
    
    return 0;
}