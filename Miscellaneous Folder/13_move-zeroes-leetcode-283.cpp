#include <bits/stdc++.h>
using namespace std ;

int main()
{
    vector<int> arr ;
    int n, x;
    cin >> n ;
    for (int i = 0; i < n; i++)
    {
        cin >> x ;
        arr.push_back(x) ;
    }
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]!=0)
        {
            swap(arr[a], arr[i]) ;
            a++ ;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr.at(i) << " " ;
    }
    cout << endl ;

    return 0;
}