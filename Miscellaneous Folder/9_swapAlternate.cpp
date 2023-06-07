
// swap alternate elements in an array
#include <iostream>
#include <cstdio>
using namespace std ;

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl ;
}
void swapArray(int array[], int n)
{
    for (int i = 0; i < n; i+=2)
    {
        if (i+1 < n)
        {
            swap(array[i], array[i+1]) ;
        }
    }
}

int main(int argc, char const *argv[])
{
    int size ;
    cout << "Enter the size of Array: " ;
    cin >> size ;
    int array[1000] ;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i] ;
    }
    cout << "Entered array: " << "\n" ;
    printArray(array, size) ;
    swapArray(array, size) ;
    cout << "Modifed array: " << "\n" ;
    printArray(array, size) ;

    return 0;
}