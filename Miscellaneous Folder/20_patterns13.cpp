#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int n ;
    cin >> n ;
    
    int row = 1;
    while (row <= 4)
    {
        int col = 1 ;
        int count = 1 ;
        while (col <= n)
        {
            if (row > col)
            {
                cout << " " << " " ;
            }
            else
            {
                cout << count << " " ;
            }
            count++ ;
            col ++ ;
        }
        cout << endl ;
        row ++ ;
    }


    return 0;
}