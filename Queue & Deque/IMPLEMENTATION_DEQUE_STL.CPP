#include <bits/stdc++.h>
using namespace std ;

void printD(deque<int> dq){
    for (auto &&i : dq)
    {
        cout << i << " " ;
    }cout << endl ;
    
}

int main(int argc, char const *argv[])
{
    deque<int> dq ;
    dq.push_front(1); dq.push_back(2); dq.push_front(3) ; // dq = 3 1 2
    printD(dq) ;

    cout << dq.front() << " " << dq.back() << endl ;
    cout << dq.size() << endl;

    dq.pop_front() ; printD(dq) ; dq.pop_back() ; printD(dq) ;
    
    return 0;
}
