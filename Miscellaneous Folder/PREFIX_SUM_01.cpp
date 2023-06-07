
/*
The basic idea behind a Prefix Sum Question is that you are given a fixed array and multiple queries of following types on the array, how to efficiently perform these queries.
*/

// Given an array, and q queries. In each query given two numbers l and r. You have to return sum of all the elements starting from index l to index r
// so one method is to run a loop for each query, expressed in method 1
// the other method is two run a prefix sum loop one time and do something such that for each loop it take O(1) time to return the result, expressed in method 2

#include <bits/stdc++.h>
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

vector<int> godFather;

void solveUsingMethod1(vector<int> v)
{
    int l, r;
    cin >> l >> r;
    int sum(0);
    for (int i = l; i <= r; i++)
    {
        sum += v[i];
    }
    cout << sum << endl;
}

void solveUsingMethod2(vector<int> v)
{
    int l, r;
    cin >> l >> r;
    if (l == 0)
    {
        cout << godFather[r];
    }
    else
    {
        cout << godFather[r] - godFather[l - 1] << endl;
    }
}

int main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        solveUsingMethod1(v);
    }

    // using method 2 ==> using godFather
    int summ(0);
    for (int i = 0; i < n; i++)
    {
        summ += v[i];
        godFather.push_back(summ);
    }
    while (q--)
    {
        solveUsingMethod2(v);
    }

    return 0;
}