
// https://www.youtube.com/watch?v=DHr-Mn_vzs0&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=144&t=231s

/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Input:
3
10 20
12 15
20 30

Output:
2

Note: The first of input contains an integer n, denoting the total number of activities given. Then n, line follows with two integers, start and end time of the nth activity. You have to output the maximum number of activities possible to be performed.
*/

#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
using namespace std ;

int main()
{
    int n;
    cin >> n ;
    vector <vi> v ;
    for (int i = 0; i < n; i++)
    {
        int start, end ;
        cin >> start >> end ;
        v.push_back({start, end}) ;
    }
    // we are making a custom comparator to sort the vector with increasing end time
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1] ;
    }) ;
    int take = 1 ;
    int end = v[0][1] ;
    for (int i = 1; i < n; i++)
    {
        if (v[i][0]>=end)
        {
            take++ ;
            end = v[i][1] ;
        }
    }
    cout << take << endl ;

    return 0;
}