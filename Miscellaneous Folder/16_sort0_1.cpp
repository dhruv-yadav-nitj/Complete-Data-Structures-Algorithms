
// method: Two Pointer method

#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int n;
    cin >> n ;
    int array[1000];
    // make an array, having 0's and 1's only
    for (int i = 0; i < n; i++)
    {
        cin >> array[i] ;
    }
    int i = 0, j = n-1 ;
    while (i <= j)
    {
        if (array[i]==0 && array[j]==1)
        {
            i++ , j-- ;
        }
        else if (array[i]==1 && array[j]==0)
        {
            swap(array[i], array[j]);
            i++ , j-- ;
        }
        else if (array[i]==0 && array[j]==0)
        {
            i++ ;
        }
        else if (array[i]==1 && array[j]==1)
        {
            j-- ;
        }        
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " " ;
    }
    cout << endl; 

    return 0;
}