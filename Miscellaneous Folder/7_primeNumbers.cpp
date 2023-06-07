#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int num ;
    cout << "Enter some number: " ;
    cin >> num ;

    int count = 0; 
    
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            count ++ ;
        }
        else
        {
            continue; 
        }
        
    }
    
    if (count == 0 && num != 1 || num == 2 || num == 3)
    {
        cout << "Prime Number" << endl; 
    }
    else
    {
        cout << "Composite Number" << endl ;
    }

    return 0;
}