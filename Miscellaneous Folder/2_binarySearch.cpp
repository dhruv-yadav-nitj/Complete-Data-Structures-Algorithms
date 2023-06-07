#include <bits/stdc++.h>
using namespace std ;

int binarySearch(int array[],int n, int key)
{
    int s=0 , e = n-1 ;
    while (s <=e)
    {
        int mid = s + (e-s)/2;
        if (array[mid]==key)
        {
            return mid ;
        }
        else if (array[mid]>key)
        {
            e = mid-1 ;
        }
        else if (array[mid]<key)
        {
            s = mid+1 ;
        }
    }
    return -1 ;
}
int main()
{
    int array[100];
    int n;
    cin >> n ;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i] ;
    }
    int key;
    cin >> key ;
    cout << "Element found at index: " << binarySearch(array, n, key) << endl ;

    return 0;
}