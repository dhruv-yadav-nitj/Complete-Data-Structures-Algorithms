#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int amt;
    cout << "Enter the Amount: " ;
    cin >> amt ;

    int count100 = 0, count50 = 0, count20 = 0, count1 = 0;
    while (amt != 0)
    {
        count100 = amt/100;
        amt %= 100;
        count50 = amt/50;
        amt %= 50;
        count20 = amt/20;
        amt %= 20;
        count1 = amt/1;
        amt %= 1;
    }
    
    cout << count100 << " x Rs100\n" << count50 << " x Rs50\n" << count20 << " x Rs20\n" << count1 << " x Rs1" << endl ;
    return 0;
}