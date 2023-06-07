
// https://www.geeksforgeeks.org/array-rotation/

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

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void rotateArray_Method1(int arr[], int n, int d)
{
    // Naive Method
    // time complexity : O(n)
    // space complexity : O(n)
    /* Approach :
    Follow the steps below to solve the given problem.
    Initialize a temporary array(temp[n]) of length same as the original array
    Initialize an integer(k) to keep a track of the current index
    Store the elements from the position d to n-1 in the temporary array
    Now, store 0 to d-1 elements of the original array in the temporary array
    Lastly, copy back the temporary array to the original array */
    int temp[n];
    int index(0);
    for (int i = d; i < n; i++)
    {
        temp[index] = arr[i];
        index++;
    }

    for (int i = 0; i < d; i++)
    {
        temp[index] = arr[i];
        index++;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
    printArray(arr, n);
}

void rotateArray_Method2(int arr[], int n, int d)
{
    // Rotate the array one by one position d number of times
    while (d--)
    {
        int temp = arr[0];
        for (int i = 1; i < n; i++)
        {
            arr[i - 1] = arr[i];
        }
        arr[n - 1] = temp;
    }
    printArray(arr, n);
    // time complexity : O(d * n)
    // space complexity : O(1)
}

// Juggling Algorithms
void rotateArray_Method3(int arr[], int n, int d)
{
    // time complexity: O(n)
    // space complexity : O(1)
    d = d % n; // to handle if d >= n
    int gcd = __gcd(n, d);
    for (int i = 0; i < gcd; i++)
    {
        int temp = arr[i];
        int j = i;

        while (1)
        {
            int k = j + d;
            if (k >= n)
            {
                k = k - n;
            }

            if (k == i)
            {
                break;
            }

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
    printArray(arr, n);
}

int main()
{
    IOS;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int d;
    cin >> d;
    rotateArray_Method1(arr, n, d);
    rotateArray_Method2(arr, n, d);

    // most important method (Using Juggling Algorithm)
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    d = 2;
    rotateArray_Method3(arr3, sizeof(arr3)/sizeof(arr3[0]), d);

    return 0;
}