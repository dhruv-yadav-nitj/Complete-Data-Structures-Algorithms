
#include <iostream>
#include <cstdio>
using namespace std ;

int fibonacci(int n) // used recursion (though he has not tought it till now)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n ==2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1)+fibonacci(n-2) ;
    }    
}

int main(int argc, char const *argv[])
{
    cout << "Enter the number: ";
    int n;
    cin >> n ;
    cout << "Ans: " << fibonacci(n) << endl ;
    return 0;
}