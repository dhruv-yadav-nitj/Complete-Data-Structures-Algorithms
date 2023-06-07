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
        while (col <= n)
        {
            if (row + col > n)
            {
                cout << '*' << " " ;
            }
            else
            {
                cout << " " <<  " " ;
            }
            col++ ;
        }
        cout << endl ;
        row++ ;
    }
    

    return 0;
}