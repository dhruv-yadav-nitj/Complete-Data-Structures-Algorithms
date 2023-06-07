/*
// program to print integers from 1 to n using recursive approach
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

void print(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    print(n - 1);
    cout << n << " " ;
}

int main()
{
    int n;
    cin >> n;
    print(n);

    return 0;
} */

/*
// program to print integers from n to 1
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

void print(int n, int i)
{
    if (i == n)
    {
        cout << i << " ";
        return;
    }
    print(n, i + 1);
    cout << i << " ";
}

int main()
{
    int n;
    cin >> n;
    print(n, 1);

    return 0;
} */

/*
// program to calculate the factorial of a number
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

l factorial(int n)
{
    // providing solution to base conditon
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n) << endl;

    return 0;
} */

/*
// program to print nth fibonacci number
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

int fib(int n)
{
    if (n == 1 or n == 0)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl ;

    return 0;
} */

/*
// program to print fibonacci series upto n terms
// remember one thing to print the series you have to use a loop
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

int fib(int n)
{
    if (n == 1 or n == 0)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << fib(i) << " ";
    }
    cout << endl;

    return 0;
} */

/*
// reverse an array using recursion
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

void f(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    swap(arr[s], arr[e]);
    f(arr, s + 1, e - 1);
}

int main()
{
    int arr[] = {2, 4, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    f(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
} */

/*
// check palindrome using recursion
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

bool f(string str, int s, int e)
{
    if (str[s] != str[e])
    {
        return false;
    }
    f(str, ++s, --e);
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (f(s, 0, s.length() - 1))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
} */

// if the ques is asking for some subsequences then always think in the way of take and not take method

/*
// print all the subsequences of an array
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

void f(int arr[], int n, int id, vi sub)
{
    // base condition
    if (id == n)
    {
        if (sub.size() == 0)
        {
            cout << "{ }";
        }

        for (auto x : sub)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    // take the element at the current  index in the sub
    sub.push_back(arr[id]);
    f(arr, n, id + 1, sub);

    // not take the element at the current index in the sub i.e., delete the element at last element taken previous
    sub.pop_back();
    f(arr, n, id + 1, sub);
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vi sub;
    f(arr, n, 0, sub);

    return 0;
} */

/*
// program to print all the subsequences of an array with sum equals to k
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

void f(int arr[], int n, int id, vi sub, int sum, int k)
{
    // base condition
    if (id == n)
    {
        if (sum == k)
        {
            for (auto x : sub)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }

    // take the element at the current  index in the sub
    sub.push_back(arr[id]);
    sum += arr[id];
    f(arr, n, id + 1, sub, sum, k);

    // not take the element at the current index in the sub i.e., delete the element at last element taken previous
    sub.pop_back();
    sum -= arr[id];
    f(arr, n, id + 1, sub, sum, k);
}

int main()
{
    // Dry Run - Test Case
    // 10
    // 2 2 2 2 4 5 5 10 10 6
    // 10
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vi sub;
    f(arr, n, 0, sub, 0, k);

    return 0;
} */

/*
// print exactly one subsequence of a given array with sum k
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
using namespace std;

bool f(int arr[], int n, int id, vi sub, int sum, int k)
{
    // base condition
    if (id == n)
    {
        if (sum == k)
        {
            for (auto x : sub)
            {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    // take the element at the current  index in the sub
    sub.push_back(arr[id]);
    sum += arr[id];
    if (f(arr, n, id + 1, sub, sum, k))
    {
        return true;
    }

    else
    {
        // not take the element at the current index in the sub i.e., delete the element at last element taken previous
        sub.pop_back();
        sum -= arr[id];
        if (f(arr, n, id + 1, sub, sum, k))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    // Dry Run - Test Case
    // 10
    // 2 2 2 2 4 5 5 10 10 6
    // 10
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vi sub;
    f(arr, n, 0, sub, 0, k);

    return 0;
} */

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
}