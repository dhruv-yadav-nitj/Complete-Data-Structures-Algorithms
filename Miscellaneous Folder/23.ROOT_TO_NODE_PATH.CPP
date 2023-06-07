// https://takeuforward.org/data-structure/print-root-to-node-path-in-a-binary-tree/
#include <bits/stdc++.h>
using namespace std ;

struct node {
  int data;
  struct node * left, * right;
};

bool doWork(node* root, vector<int>&ans, int target){
    // main-recursive-function

    if(root == NULL){return false ;} // agar current node NULL hain to kahani hi khtm

    ans.push_back(root -> data) ; // push the current node to the ans vector

    if(root -> data == target){return true ;} // agar current node hi target hain to true return kro

    if(doWork(root -> left, ans, target) or doWork(root -> right, ans, target)){return true ;} // agar current node ka left or right subtree dono mein se kisi mein bhi target lie krta hain to true return kr do

    ans.pop_back() ; return false ;
}

int main(int argc, char const *argv[])
{
    node *root = NULL ; root = new node() ; int target ;
    vector<int> ans ; bool flag = doWork(root, ans, target) ;
    return 0;
}
