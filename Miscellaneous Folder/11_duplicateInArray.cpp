
// https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397
// Duplicate In Array

#include <bits/stdc++.h>
using namespace std ;

void doWork (int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (array[i]==array[j])
            {
                cout << array[i] << endl ;
            }
        }
    }
    
}

int main()
{
    int t;
    cin >> t ;
    for (int i = 0; i < t; i++)
    {
        int array[100000] ;
        int n ;
        cin >> n ;
        for (int i = 0; i < n; i++)
        {
            cin >> array[i] ;
        }
        doWork(array, n) ;
        
    }
    

    return 0;
}

/*

int findDuplicate(vector<int> &arr)
{
    int ans = 0;
	
// 	XORing all the elements
	for (int i = 0; i < arr.size() ;i++)
	{
		ans = ans ^ arr[i];
	}
// 	XOR[1, N-1]
	for(int i = 0; i < arr.size(); i++)
	{
		ans = ans ^ i;
	}
	return ans;
}

*/