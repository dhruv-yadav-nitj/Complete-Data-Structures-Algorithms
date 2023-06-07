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


// approach #1 : brute force
// get the inorder of the given tree --> sort the inorder to get the correct inorder that should be according to the property of the bst
// now again traverse the bst and compare the values of inorder with the nodes if they are not equal then make then equal

class Solution {
public:
    void getInorder(TreeNode* curr, vector<int> &inorder){
        if(curr == NULL){return ;}
        getInorder(curr -> left , inorder) ;
        inorder.push_back(curr -> val) ; getInorder(curr -> right, inorder) ;
    }

    void correction(TreeNode*curr, vector<int> inorder, int &counter){
        if(curr == NULL){return ;}

        // main-code
        correction(curr -> left, inorder, counter) ;
        curr -> val = inorder[counter++] ;
        correction(curr -> right, inorder, counter) ;
    }
    void recoverTree(TreeNode* root) {

        vector<int> inorder ; getInorder(root , inorder) ;
        sort(inorder.begin(), inorder.end()) ; // correcting the inorder
        int counter = 0 ; correction(root, inorder, counter) ;
    }
};

// approach #2: unlike the first approach in which we first find the inorder traversal , sort it then compare the whole tree with it --> in this approach we would not first find the inorder traversal but would use pointers instead

class Solution {

    TreeNode *prev, *first, *mid, *last ;

    void inorder(TreeNode* root){

        // normal base condition of inorder traversal
        if(root == NULL){return ;}

        // first comes left
        inorder(root -> left) ;


        // this is where we do the real business --> comparing the current node with previous one
        if(prev != NULL and (root -> val < prev -> val)){
            
            if(first == NULL){ // means it is the first violation
                first = prev ; mid = root ;
            }
            else{
                last = root ;
            }
        }

        // change prev and move to the right
        prev = root ; inorder(root -> right) ;
    }

public:
    void recoverTree(TreeNode* root) {

        // code here

        first = mid = last = NULL ;
        prev = new TreeNode(INT_MIN) ; inorder(root) ;

        if(first != NULL and last != NULL){
            swap(first -> val, last -> val) ;
        }
        else if(first != NULL and mid != NULL){
            swap(first -> val, mid -> val) ;
        }
    }
};


// code i wrote by myself on leetcode IDE


class Solution {

    TreeNode *prev, *first, *mid, *last;

    void inorderTraversal(TreeNode* curr){

        // base condition
        if(!curr){return ;}

        // left --> root --> right
        // first comes left
        inorderTraversal(curr -> left) ;

        // then root
        // here we will compare

        if(prev != NULL and curr -> val < prev -> val){

            if(first == NULL){
                // means its the first violation
                first = prev ; mid = curr ;
            }

            else{
                // means its the second violation
                last = curr ;
            }
        }

        prev = curr ;
        // then right
        inorderTraversal(curr -> right) ;
    }


public:
    void recoverTree(TreeNode* root) {

        // code here - main - solution - function

        prev = first = mid = last = NULL ;

        inorderTraversal(root) ;

        if(first and last){
            swap(first -> val, last -> val) ;
        }
        else if(first and mid and !last){
            swap(first -> val , mid -> val) ;
        }
        
    }
};