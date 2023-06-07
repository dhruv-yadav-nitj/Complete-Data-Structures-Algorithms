
// https://www.codingninjas.com/codestudio/problems/pair-sum_697295?leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

void findSum(int array[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (array[i] + array[j] + array[k] == sum)
                {
                    cout << array[i] << " " << array[j] << " " << array[k] << endl;
                    array[i] = INT_MIN;
                    array[j] = INT_MIN;
                    array[k] = INT_MIN;
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int array[1000];
        for (int j = 0; j < n; j++)
        {
            cin >> array[j];
        }
        int sum;
        cin >> sum;
        findSum(array, n, sum);
    }

end:
    return 0;
}

/*

vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{

    // Write your code here.

    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    int left, right;

    for (int i = 0; i < n; i++)

    {

        left = i + 1;

        right = n - 1;

        while (left < right)

        {

            if (arr[left] + arr[right] + arr[i] == K)

            {

                ans.push_back({arr[i], arr[left], arr[right]});

                int x = arr[left];

                int y = arr[right];

                // skipping same elements

                while (left < right && arr[left] == x)
                {

                    left++;
                }

                while (left < right && arr[right] == y)
                {

                    right--;
                }
            }

            else if (arr[left] + arr[right] + arr[i] < K)
            {

                left++;
            }

            else
            {

                right--;
            }
        }

        // skipping same ith element

        while (i + 1 < n && arr[i] == arr[i + 1])
        {

            i++;
        }
    }

    return ans;
}

* /