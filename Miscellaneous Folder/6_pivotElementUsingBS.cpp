#include <bits/stdc++.h>
using namespace std ;

int findPivot (int array[] , int n)
{
    int s = 0, e= n-1 ;
    int mid ;
    while (s<e)
    {
        mid = s + (e-s)/2 ;
        if (array[mid]>=array[0])
        {
            s = mid+1 ;
        }
        else if (array[mid]<array[0])
        {
            e = mid ;
        }
        
    }
    return array[s] ;
    
}

int main()
{
    int array[] = {8, 10, 17, 1, 2, 3} ;
    cout << "Pivot Element : " << findPivot(array, sizeof(array)/sizeof(int)) << endl ;

    return 0;
}