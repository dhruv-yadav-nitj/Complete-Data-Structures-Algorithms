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
    while (row <= n)
    {
        
        // code for 1st triangle (space wala)
        int col = n-row ;
        while (col != 0)
        {
            cout << " " << " " ;
            col-- ;
        }
        

        // 2nd triangle 
        int j = 1;
        while (j <= row)
        {
            cout << j << " " ;
            j++ ;
        }
        
        // 3rd triangle
        int k = row - 1;
        while (k != 0)
        {
            cout << k << " " ;
            k-- ;
        }
        

        cout << endl ;
        row++ ;
    }
    

    return 0;
}