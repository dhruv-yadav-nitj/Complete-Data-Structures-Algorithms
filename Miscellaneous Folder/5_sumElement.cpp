
// sum of all the elements of an array
#include <iostream>
#include <cstdio>
using namespace std ;

int sumElement(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i] ;
    }
    return sum ;
}

int main(int argc, char const *argv[])
{
    int array[1000] ;
    int size ;
    cout << "Enter the size: ";
    cin >> size ;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i] ;
    }
    cout << sumElement(array, size) << endl ;
    return 0;
}