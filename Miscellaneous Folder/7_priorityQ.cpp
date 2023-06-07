#include <bits/stdc++.h>
using namespace std ;

int main()
{
    // max-heap
    // the largest data would be fetched first and so on
    priority_queue<int> maxi ;
    maxi.push(1) ;
    maxi.push(4) ;
    maxi.push(2) ;
    maxi.push(0) ;

    cout << "Size of maxi --> " << maxi.size() << endl ;
    int size_maxi = maxi.size() ;
    for (int i = 0; i < size_maxi; i++)
    {
        cout << maxi.top() << " " ; // maxi.top() means the first element (in case of priority_queue it would be the greatest element)
        maxi.pop () ; // means remove the first element
    }cout << endl ;
    
    // min-heap
    priority_queue<int, vector<int>, greater<int> > mini ;
    mini.push(1) ;
    mini.push(4) ;
    mini.push(2) ;
    mini.push(0) ;
    
    int m = mini.size() ;
    for (int i = 0; i < m; i++)
    {
        cout << mini.top() << " " ;
        mini.pop() ;
    }cout << endl ;

    cout << "Is empty ? --> " << mini.empty() << endl ;
    

    return 0;
}