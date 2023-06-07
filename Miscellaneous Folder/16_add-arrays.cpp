
// https://www.geeksforgeeks.org/add-two-numbers-represented-by-two-arrays/?ref=gcse

// TC : O(n+m) 
// SC : O(max(n,m))


#include <bits/stdc++.h>
using namespace std ;

int printSum (int a[], int b[], int n, int m)
{
    // please note that the size of arr1 i.e. n is always greater than or equal to sizeof arr2 i.e. m

    vector <int> ans ;
    int i=n-1, j=m-1;

    int carry=0, sum=0 ;
    while (j>=0)
    {
        sum = a[i]+b[j]+carry ;
        ans.push_back(sum%10) ;
        carry = sum/10 ;

        i-- ; j-- ;
    }
    
    while (i>=0)
    {
        sum = a[i] + carry ;
        ans.push_back(sum%10) ;
        carry = sum/10 ;
        i-- ;
    }
    
    // if carry still exist

    int val = 0;
    if (carry)
    {
        val = 10 ;
    }
    
    reverse(ans.begin(), ans.end()) ;
    
    for (int i = 0; i < n; i++)
    {
        val += ans[i] ;
        val *= 10 ;
    }
    return val/10 ;

}

int main()
{
    int a[] = {9, 9, 9} , b[] = {9, 9} ;
    int n = sizeof(a)/sizeof(a[0]) ;
    int m = sizeof(b)/sizeof(b[0]) ;

    if (n>=m)
    {
        cout << printSum(a, b, n, m) << endl ;
    }
    else
    {
        cout << printSum(b, a, m , n) << endl ;
    }
    
    return 0;
}