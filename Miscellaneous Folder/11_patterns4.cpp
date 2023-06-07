#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int n ;
    cout << "Enter the order of sqaure matrix: " ;
    cin >> n ;

    int num = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; num++ , j++)
        {
            if (num < 10)
            {
                cout << 0 << num << " " ;
            }
            else
            {
                cout << num << " " ;
            }
            
            
        }
        cout << "\n" ;
    }
    
    return 0;
}