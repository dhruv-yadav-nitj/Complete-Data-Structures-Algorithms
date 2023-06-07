#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// we have to design a special class for this approach
class BSTiterator{
    stack<TreeNode*> myStack ; bool reverse = true ;
    // reverse = true --> means before and reverse = false --> means next
public:
    BSTiterator(TreeNode* root, bool isReverse){
        reverse= isReverse ;
        pushAll(root) ;
    }

    void pushAll(TreeNode* curr){
        while(curr != NULL){
            myStack.push(curr) ;
            if(reverse){
                curr = curr -> right ;
            }
            else{curr = curr -> left ;}
        }
    }

    bool hasNext(){
        return !myStack.empty() ;
    }

    int next (){
        TreeNode* temp = myStack.top() ; myStack.pop() ;
        if(reverse){
            // inorder ka yeh charitra hota hain left root right --> jb bhi hm kisi node se pass ho rhe then uske baad hme right mein jaana hain --> aisa tb krte hain jb hme next iterator design krna hota hain to before iterator mein theek iska ulta hoga
            pushAll(temp -> left) ;
        }
        else{pushAll(temp -> right) ;}

        return temp -> val ;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {


        // code here
        BSTiterator l(root, false) ; BSTiterator r(root, true);
        // l stands for next iterator and r means before iterator

        int i = l.next(), j = r.next() ;

        while(i < j){
            if(i + j == k){return true ;}
            else if(i + j < k ){
                i = l.next() ;
            }
            else{j = r.next() ;}
        }

        return false ;

    }
};