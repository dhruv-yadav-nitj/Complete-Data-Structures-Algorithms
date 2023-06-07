// https://www.geeksforgeeks.org/next-smaller-element/
/* Here we maintain items in increasing order in the stack (instead of decreasing in next greater element problem).

Push the first element to stack.
Pick rest of the elements one by one and follow following steps in loop.
Mark the current element as next.
If stack is not empty, then compare next with stack top. If next is smaller than top then next is the NSE for the top. Keep popping from the stack while top is greater than next. next becomes the NSE for all such popped elements
Push next into the stack
After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.
Note: To achieve the same order, we use a stack of pairs, where first element is the value and second element is index of array element.  */

// read the above notes and use copy pen while revising
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
#define loop(i, low, high) for(int i= low; i < high;i++) 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// time complexity: O(n)
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // initialise a vector with all the initial values as -1
    vi ans(n, -1);
    stack<pair<int, int>> s;
    loop(i, 0, n){
        if(s.empty()){
            s.push({arr[i], i}) ;
        }
        else{
            while(!s.empty() and s.top().first > arr[i]){
                ans[s.top().second] = arr[i] ; s.pop() ;
            }
            s.push({arr[i], i}) ;
        }
    }return ans;
}