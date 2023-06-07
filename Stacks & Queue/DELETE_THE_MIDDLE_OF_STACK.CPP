// delete the middle of stack in-place
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack){
        // according to given constraint we can use O(n) time and space complexities.
        stack<int> temp ; int mid = ceil(s.size() / 2.0) ;
        while(!s.empty()){temp.push(s.top()); s.pop() ;}
        int count(1);
        while(!temp.empty()){
            if(count != mid){
                s.push(temp.top()) ;
            }
            temp.pop() ; count++ ;
        }
    }
    // there's a recursive solution as well
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends