#include <bits/stdc++.h>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

// approach : https://www.geeksforgeeks.org/convert-bst-min-heap/

// summary: given that BST is already a complete binary tree --> so we need not care about that thing

// we would use two things --> inorder traversal of BST is sorted array and in min Heap --> root < left and right
// we can use one more thing --> we can make a min Heap in which left < right --> mtlb hme to bs aisa krna hain ki root apne left aur right child se cchota rhe --> to usme hm log ek aur cheej add kr skte hain --> ki left < right but left > root --> which makes root < left < right (which makes the traversal preorder jaisa kuch)

// step 1: extract inorder traversal of the bst
// step 2: traverse the bst preorder wise and ek line se bs value put krte jaao

// to understand more clearly --> dry run on : 4 2 6 1 3 5 7 (bsf traversal of a bst)

class BinaryTreeNode
{

public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

void inorderT (BinaryTreeNode* root , vector<int> &inorder){

    // base condition
    if(root == NULL){return ;}

    inorderT(root -> left,  inorder) ;

    inorder.push_back(root -> data) ; inorderT(root -> right , inorder) ;

}

void convertBSTtoMinHeap (BinaryTreeNode* root , int &i, vector<int> inorder){

    // base condition
    if(root == NULL){return ;}


    // preorder wise travel krenge --> bcz root < left < right
    root -> data = inorder[i++] ;
    convertBSTtoMinHeap(root -> left , i , inorder) ;
    convertBSTtoMinHeap(root -> right , i , inorder) ;
}

BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    // Write your code here.

    vector<int> inorder ; inorderT(root , inorder) ;

    // so now we have the inorder traversal of the BST --> which is sorted
    int i =0 ;
    convertBSTtoMinHeap(root , i , inorder) ;
    return root ;
}
