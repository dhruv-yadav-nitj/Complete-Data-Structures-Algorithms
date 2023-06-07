#include <bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[])
{
    queue<int> q ;
    q.push(1) ; q.push(2) ; q.push(3) ; q.push(4) ;
    cout << q.back() << endl ; cout << q.front() << endl ;
    q.pop() ; cout << q.front() << endl;

    cout << q.size() << endl; 
    if(q.empty()){cout << "Yes" << endl ;} else{cout << "No" << endl ;}

    queue<int> q2 ; q2.push(100) ; q.swap(q2) ; cout << q.front() << " " << q2.front() << endl ;

    return 0;
}
