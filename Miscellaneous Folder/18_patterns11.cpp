#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int n ;
    cin >> n ;

    int row = 1 ;
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << (char)('A' + (col + 3 - row)) << " " ;
            col ++ ;
        }
        cout << endl ;
        row ++ ;
    }
    

    return 0;
}