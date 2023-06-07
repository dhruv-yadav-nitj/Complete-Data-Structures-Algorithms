
// Reverse printing an array (its not actual reversing an array)

#include <iostream>
#include <cstdio>
using namespace std ;

int main(int argc, char const *argv[])
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 6; i >= 0; i--)
    {
        cout << array[i] << " " ;
    }
    cout << endl ;

    return 0;
}