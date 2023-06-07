//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    // always use static
    static bool customSort(Item a, Item b)
    {
        double val1 = (double)a.value / (double)a.weight;
        double val2 = (double)b.value / (double)b.weight;
        return val1 > val2;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Approach: phle to hme sort krna hain array according to the value per weight of items. we woudl sort the array in order of decreaing value/weight. after that we would keep taking those items in the knapsack until the ith item has weight larger than remaining capacity of knapsack. then at this point we would fill the remaining capacity with some part of the current item. ans += (rem capacity * (value/weight))
        sort(arr, arr + n, customSort);
        double ans = 0.0;
        for (int i = 0; i < n and W > 0; i++)
        {
            if (W >= arr[i].weight)
            {
                ans += (double)arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                ans += (W * ((double)arr[i].value / (double)arr[i].weight));
                W = 0;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends