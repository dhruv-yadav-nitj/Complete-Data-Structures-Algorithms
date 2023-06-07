
// Problem Statement
// We are given an array and all the numbers except one occurs even number of times. Find the only number which occurs odd number of times.

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

int doSolve(int arr[], int n)
{
    int temp(0);
    for (int i = 0; i < n; i++)
    {
        temp = (temp ^ arr[i]);
    }
    return temp;
}
/* 
temp = 0
temp = 0 ^ 4 ^ 3 ^ 4 ^ 4 ^ 4 ^ 5 ^ 5 ^ 3 ^ 3 = (4 ^ 4 ^ 4 ^ 4) ^ (5 ^ 5) ^ (3 ^ 3 ^ 3) = 0 ^ 0 ^ 0 ^ 3 = 3
*/

int main()
{
    IOS;
    // we know that XOR Operator is Associative and (a XOR a)=0 and (a XOR 0)=a
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << doSolve(arr, n) << endl;

    return 0;
}