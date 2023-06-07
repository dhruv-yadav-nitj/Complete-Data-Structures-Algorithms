// https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Note: is program ko maine phle bs as it is chhap diya tha, pdha nhi tha bcz isme kuch cheeje jaise Kadane Algo use hua hain jo abhi tk hm pdhe nahi hain.
// Chapter 5 : Arrays ==> Lecture No. 24

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // num: size of array
    // Function to find maximum circular subarray sum.
    int normalMaxSum(int arr[], int n)
    {
        // kadane's Algorithm
        int res = arr[0], maxEnding = arr[0];
        for (int i = 1; i < n; i++)
        {
            maxEnding = max(arr[i], maxEnding + arr[i]);
            res = max(res, maxEnding);
        }
        return res;
    }
    int circularSubarraySum(int arr[], int num)
    {
        int maxNormal = normalMaxSum(arr, num);
        if (maxNormal < 0)
        {
            return maxNormal;
        }
        int arrSum(0);
        for (int i = 0; i < num; i++)
        {
            arrSum += arr[i];
            arr[i] = -arr[i];
        }
        int max_circular = arrSum + normalMaxSum(arr, num);
        return max(maxNormal, max_circular);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;

    // testcases
    cin >> T;

    while (T--)
    {
        int num;

        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        Solution ob;
        // calling function
        cout << ob.circularSubarraySum(arr, num) << endl;
    }

    return 0;
}
// } Driver Code Ends