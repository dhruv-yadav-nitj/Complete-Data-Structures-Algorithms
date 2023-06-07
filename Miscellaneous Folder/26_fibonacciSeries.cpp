// iterative method
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int a = 0 , b = 1 ;
    int n ;
    cout << "Enter the n for F(n): " ;
    cin >> n ;

    for (int i = 0; i < n; i++)
    {
        int t ;
        t = a ;
        a = b ;
        b = a + t ;
        cout << t << " " ;
    }
    cout << endl ;    

    return 0;
}