/*
Problem Statement
You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.
*/

void sort012(int *arr, int n)
{
    //   Write your code here
    int left = 0, right = n - 1, mid = 0;
    // initialize pointers left should cover 0, right 2 and mid = 1 ideally speaking, now code it out
    while (mid <= right)
    {
        // check for mid value, we are going to play on that, comparing mid with the target value
        if (arr[mid] == 1)
        {
            // ideal condition coz mid element needs to be 1, so move ptr
            mid++;
        }
        else if (arr[mid] < 1)
        {
            // means the value is 0
            swap(arr[mid], arr[left]);
            left++;
            mid++;
        }
        else
        {
            // if (a[mid]>1) that is the value equal to 2
            swap(arr[mid], arr[right]);
            right--; // coz we need to bring right ptr closer and not change anything else
        }
    }
}
