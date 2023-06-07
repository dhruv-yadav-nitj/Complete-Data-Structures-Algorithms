// https://www.codingninjas.com/codestudio/problems first-and-last-position-of-an-element-in-sorted-array_1082549

#include <bits/stdc++.h>
using namespace std ;

int leftMost (int array[], int n , int key)
{
    int s =0 , e = n-1, ans = -1 ;
    while (s <= e)
    {
        int mid = s + (e-s)/2 ;
        if (array[mid]==key)
        {
            ans = mid ;
            e = mid-1 ;
        }
        else if (array[mid]>key)
        {
            e = mid-1 ;
        }
        else if (array[mid]<key)
        {
            s= mid+1 ;
        }        
    }
    return ans ;
}

int rightMost (int array[], int n, int key)
{
    int s=0, e = n-1, ans =-1 ;
    while (s <=e)
    {
        int mid = s + (e-s)/2 ;
        if (array[mid]==key)
        {
            ans = mid ;
            s = mid+1 ;
        }
        else if (array[mid]<key)
        {
            s = mid+1;
        }
        else if (array[mid]>key)
        {
            e = mid-1;
        }
        
    }
    return ans ;
}

int main()
{
    int array[5000] ;
    int n, key;
    cin >> n ;
    cin >> key ;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i] ;
    }
    
    // now this question can be only solved in two seperate parts, first finding the left most occurences and then the right most occurences
    cout << leftMost(array, n , key) << " " << rightMost(array, n, key) << endl ;

    return 0;
}