
#include <iostream>
#include <cstdio>
using namespace std ;

void updater(int array[] , int size)
{
    array[0] = 120 ;
    cout << "Start" << "\n" ;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " " ;
    }
    cout << "\n" << "Exit" << endl ;
}

int main(int argc, char const *argv[])
{
    int array[] = {1, 2, 3} ;
    updater(array, 3) ;
    for (int i = 0; i < 3; i++)
    {
        cout << array[i] << " " ;
    }
    cout << endl ;
    return 0;
}