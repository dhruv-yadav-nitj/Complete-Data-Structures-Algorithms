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

// method 1 : NEWBIE METHOD
l factorial(int n)
{
    l temp(1);
    for (int i = 1; i <= n; i++)
    {
        temp *= i;
    }
    return temp;
}

// method 2 : OPTIMIZED METHOD
int trailing_Zeros(int n)
{
    int count(0);
    // Logic Used: A trailing zero would occur when 5 and 2 would occue together, since it is clearly observed that number of 5 is less than number of 2s in any factorial, so we would count number of 5s..

    /*
    We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s. So if we count 5s in prime factors, we are done. How to count the total number of 5s in prime factors of n!? A simple way is to calculate floor(n/5). For example, 7! has one 5, 10! has two 5s. It is not done yet, there is one more thing to consider. Numbers like 25, 125, etc have more than one 5. For example, if we consider 28! we get one extra 5 and the number of 0s becomes 6. Handling this is simple, first, divide n by 5 and remove all single 5s, then divide by 25 to remove extra 5s, and so on. Following is the summarized formula for counting trailing 0s. */
    for (int i = 5; i <= n; i *= 5)
    {
        count += n / i;
    }
    return count;
}

int main()
{
    IOS;
    // trailing zeros means the number of zeros at the end of a number
    // example: 1000 has 3 trailing zeros and 1560700 has 2 trailing zeros
    int n;
    cin >> n;
    l factos = factorial(n);

    int count(0);
    while (factos % 10 == 0)
    {
        count++;
        factos /= 10;
    }
    cout << count << endl;

    // using method 2
    cout << trailing_Zeros(n) << endl;

    return 0;
}