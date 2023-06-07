// C++ Program to find two numbers
// with difference of their
// squares equal to N

#include <bits/stdc++.h>
using namespace std;

// Function to check and print
// the required two positive integers
void solve(int n)
{

    // Iterate till sqrt(n) to find
    // factors of N
    for (int x = 1; x <= sqrt(n); x++)
    {

        // Check if x is one
        // of the factors of N
        if (n % x == 0)
        {

            // Store the factor
            int small = x;

            // Compute the other factor
            int big = n / x;

            // Check if the two factors
            // are of the same parity
            if (small % 2 == big % 2)
            {

                // Compute a and b
                int a = (small + big) / 2;
                int b = (big - small) / 2;

                cout << a << " "
                     << b << endl;
                return;
            }
        }
    }

    // If no pair exists
    cout << -1 << endl;
}

// Driver Code
int main()
{
    int n;
    cin >> n;

    solve(n);

    return 0;
}
