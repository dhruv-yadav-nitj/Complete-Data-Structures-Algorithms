#include <iostream>
#include <cstdio>
using namespace std ;

void printArray(int array[] , int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " " ;
    }
    cout << "\tPrinting Done." << endl ;
}

int main(int argc, char const *argv[])
{
    int first[15] = {1, 2, 3, 4, 5}  ;
    printArray(first, 15) ; // it is necessary to provide the length of array to pass in the function

    int second[20] = {5, 6, 7, 8, 9, 10} ;
    printArray(second, 20) ;

    return 0;
}