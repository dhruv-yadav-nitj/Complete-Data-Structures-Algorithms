#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

// Bitwise operator simply means the operators that work on bit level. If you wanna understand how a particular BITWISE Operator works then simply convert the number from Decimal format to Binary format.

int main()
{
    IOS;
    int a, b;
    cin >> a >> b;

    // AND Operator
    // if a single input is 0 then output is 0
    cout << a << " AND " << b << " = " << (a & b) << endl;

    // OR Operator
    // if a single input is 1 then output is 1
    cout << a << " OR " << b << " = " << (a | b) << endl;

    // XOR Operator
    // output is 1 if both the inputs are different and output is 0 if both inputs are same
    cout << a << " XOR " << b << " = " << (a ^ b) << endl;

    // BITWISE Calculations are always done under braces.

    // LEFT SHIFT Operator
    // Shifts all the set bits to left by some specified places
    cout << a << " LSH by 2 = " << (a << 2) << endl;
    // Left Shift simply means
    // (a<<m) == a * (pow(2, m))

    // RIGHT SHIFT Operator
    // Shifts all the set bits to right by some specified places
    cout << b << " RSH by 2 = " << (b >> 2) << endl;
    // Right Shift simply means
    // (a>>m) == a / (pow(2, m))

    // NOT Operator
    // Does 1 ka 0 and 0 ka 1
    cout << "NOT " << a << " = " << (~a) << endl ;
    // NOT (n) = -n-1

    // 0 at MSB represents (+)ve number and 1 at MSB represents (-)ve numbers.
    /* For signed binary numbers the most significant bit (MSB) is used as the sign bit. If the sign bit is “0”, this means the number is positive in value. If the sign bit is “1”, then the number is negative in value. */
    // LSH and RSH are not recommended on Negative Numbers since the behaviour is undefined according to C++ Standards.

    return 0;
}