// Reverse an Array
#include <bits/stdc++.h>
using namespace std ;

void doReverse(int array[], int size)
{
    int start = 0 , end = size-1 ;
    while (start<end)
    {
        swap(array[start], array[end]) ;
        start++ ;
        end-- ;
    }
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " " ;
    }
    cout << endl ;
}
int main()
{
    int array[1000] ;
    int size; 
    cin >> size ;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i] ;
    }
    doReverse(array, size) ;
    printArray(array, size);
    return 0;
}