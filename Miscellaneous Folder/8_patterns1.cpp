#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int n ;
    cin >> n ;

    int i = 1 ;

    while (i <= n)
    {
        int j =1 ;
        while (j <= n)
        {
            cout << '*' ;
            j ++ ;
        }
        cout << "\n" ;
        i++ ;
    }
    

    return 0;
}