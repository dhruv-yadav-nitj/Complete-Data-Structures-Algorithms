/* #include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
#define loop(i, low, high) for(int i= low; i < high;i++) 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

void solve()
{
    // we have prev approaches to do the same thing like using two pointer approach having better time and space complexities
    // Time Complexity: O(n) and Space Complexity: O(n)
    string inp;  cin >> inp; stack<char> s;
    for (auto &&i : inp)
    {
        s.push(i) ;
    } string ans = "" ;
    while(!s.empty()){
        ans += s.top() ; s.pop() ;
    }cout <<ans << endl;
}

int main()
{
    IOS;
    l t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    return 0;
} */

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}


// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
    stack<char> s ;
    for(int i= 0; i < len; i++){s.push(*(S+i)) ;}
    int j(0);
    while(!s.empty()){*(S+j) = s.top() ; s.pop() ; j++;}return S ;
}