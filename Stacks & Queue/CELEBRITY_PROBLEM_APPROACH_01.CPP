//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        for(int i=0; i< n; i++){
            // i represents person
            
            // first we need to check if this person knows someone or not, if he knows atleast one person, then he cannot be the celebrity so we need not check further, for this perons to be celebrity every value in this row must be zero
            bool doubt = true;
            for(int col =0; col< n; col++){
                if(M[i][col] == 1){
                    doubt = false; break ;
                }
            }

            if(doubt){
                // since we have doubt on this person that he can be the celebrity we need to check if everyone knows him or not
                bool cnf = true ; //assume everyone knows him
                for(int row=0; row< n; row++){
                    if(M[row][i] == 0 and row != i){
                        cnf = false; break; // if there is a single person (row) other than ith row in which the value at this column is 0 then this person is not the celebrity.
                    }
                }
                if(cnf){return i ;}
            }
        }return -1 ;
        // clearly the above solution is having O(n2) time complexity which can be further optimised using stacks
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends