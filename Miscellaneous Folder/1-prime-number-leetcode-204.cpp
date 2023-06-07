
// Approach 1 :
// Square Root Method

/* class Solution
{
public:
    bool isPrime (long long n)
    {
        for (long long i = 2; i*i < n; i++)
        {
            if (n%i==0)
            {
                return false ;
            }

        }
        return true ;
    }
    int countPrimes(int n)
    {
        long long count = 0;
        for (long long i = 2; i < n; i++)
        {
            if (isPrime(i))
            {
                count++;
            }
        }
        return count ;
    }
}; */

/*
Statement :
Given an integer n, return the number of prime numbers that are strictly less than n.
*/

// Approach 2
// Sieve of Eratosthenes
/*
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define vp vector<vector<int>>
using namespace std ;

void doAlgo(int n)
{
    // so we have to create a bool array and intialise all its value with true
    bool prime[n+1] ;
    // memset is used to copy a value to all the index of an array
    memset (prime, true, sizeof(prime)) ;

    for (int i = 2; i*i <= n; i++)
    {
        if (prime[i]==true)
        {
            for (int j =i*i; j <= n; j+=i)
            {
                prime[j] = false ;
            }
        }
    }
    int count =  0;
    for (int i = 2; i <= n ; i++)
    {
        if (prime[i])
        {
            count++ ;
        }

    }
    cout << count << endl ;

}

int main()
{
    int n ;
    cin >> n ;
    doAlgo(n) ;

    return 0;
}
 */

class Solution
{
public:
    int countPrimes(int n)
    {
        // Create a boolean array "prime[0 ........... n]" and initialize
        // all entries it as true. A value in prime[i] will
        // finally be false if i is Not a prime, else true.
        
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        for (int i = 2; i < n; i++)
        {
            if (prime[i] == true)
            {
                for (int j = i * i; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i] == true)
            {
                count++;
            }
        }
        return count;
    }
};