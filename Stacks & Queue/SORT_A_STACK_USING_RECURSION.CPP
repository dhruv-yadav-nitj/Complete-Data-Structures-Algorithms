#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
#define loop(i, low, high) for(int i= low; i < high;i++) 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

void insertSorted(stack<int>& s, int nums){
    if((s.empty())  or (s.top() < nums)){
        s.push(nums); return ;
    }

    int temp = s.top() ; s.pop() ;
    insertSorted(s, nums) ;

    s.push(temp) ;
}

void sortStack(stack<int> &s){

    // base case
    if(s.empty()){
        return ;
    }

    int nums = s.top() ; // store the top element of the stack 
    s.pop() ;
    sortStack(s) ;

    // when the fx will return we would insert nums in sorted way
    insertSorted(s, nums) ;
}

// in the worst case this code would be having O(n2) time complexity and O(n) aux space.

void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " " ; s.pop() ;
    }cout << endl;
}

int main()
{
    IOS;
    stack<int> s ; s.push(1); s.push(7) ; s.push(5) ; s.push(6) ;
    cout << "Before Sorting: " ; print(s) ;
    sortStack(s) ;
    cout << "After Sorting: " ; print(s);

    return 0;
}