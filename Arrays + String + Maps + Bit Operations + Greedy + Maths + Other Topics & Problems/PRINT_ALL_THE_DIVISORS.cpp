// printing all the divisors is not much different from print all the prime factors
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

void printAllTheDivisors(int n)
{
    set<int> s;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            s.insert(i);
            s.insert(n / i);
        }
    }
    for (auto &x : s)
    {
        cout << x << " ";
    }
    cout << endl;
}

// we used set because it makes our work easy since the numbers are stored automatically in Non- decreasing order.

// the above code can be used in ques like PRINT_ALL_THE_PRIME_FACTOrS_ONLY_ONCE just by making small changes
// in place of cout << x << " " we can write a function to check if it is prime or not and then output x

int main()
{
    IOS;
    int n;
    cin >> n;
    printAllTheDivisors(n);

    return 0;
}