#include <iostream>
#include <cstdio>
using namespace std ;

int factorial (int num)
{
    int rem = 1;
    while (num != 1)
    {
        rem = rem * num ;
        num-- ;
    }
    return rem;
}

int main(int argc, char const *argv[])
{
    int n, r;
    cout << "Enter n and r for nCr: " ;
    cin >> n >> r ;
    int ans = (factorial(n))/(factorial(r)*factorial(n-r)) ;
    cout << "Answer: " << ans << endl ;

    return 0;
}