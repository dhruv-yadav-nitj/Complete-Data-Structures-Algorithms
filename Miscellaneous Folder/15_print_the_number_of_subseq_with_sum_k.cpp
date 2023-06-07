// this program is a variation to previous program
// we have to print the count of subsequences with sum equal to k

// Notes: since we need not print the data we can remove the vector

#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

int f(int arr[], int n, int k, int sum, int idx)
{
    if (idx == n)
    {
        if (sum == k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // take
    sum += arr[idx];
    int countTake = f(arr, n, k, sum, idx + 1) == 1;

    // not take
    sum -= arr[idx];
    int countNot_take = f(arr, n, k, sum, idx + 1) == 1;

    return countTake + countNot_take;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vi v;
    cout << f(arr, n, k, 0, 0) << endl ;

    return 0;
}


/* 
// one more method :: made by me
// printing the number of subsequences with sum k
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

int count = 0;
void f(int arr[], int n, int id, int sum, int k)
{
    if (id == n)
    {
        if (sum == k)
        {
            ::count++;
        }
        return;
    }

    // take
    sum += arr[id];
    f(arr, n, id + 1, sum, k);

    // not take
    sum -= arr[id];
    f(arr, n, id + 1, sum, k);
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    f(arr, n, 0, 0, k);
    cout << ::count << endl;

    return 0;
} */