// Tail recursion is basically a recursive function in which the recursive call is the last statement that is executed by the function. So basically nothing is left to execeute after the recursion call.

// The tail recursive functions are considered better than non tail recursive functions as tail-recursion can be optimized by the compiler.

// A non-tail recurive can be written as tail recursive function but it is not always possible.

// Among Quick Sort and Merge Sort, Quick Sort perform better since Quick Sort is a tail recursive and Merge Sort is not.
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

int factorialNonTail(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorialNonTail(n - 1);
}

int factorialUsingTailRecursion(int n, int a)
{
    if (n == 1)
    {
        return a;
    }
    return factorialUsingTailRecursion(n - 1, a * n);
}

int main()
{
    IOS;
    int n;
    cin >> n;

    // lets compare non-tail recursice function with tail recursive function
    // a non-tail recursive function can be converted to tail recursive function using an extra argument.
    cout << factorialNonTail(n) << endl;
    cout << factorialUsingTailRecursion(n, 1) << endl;

    return 0;
}