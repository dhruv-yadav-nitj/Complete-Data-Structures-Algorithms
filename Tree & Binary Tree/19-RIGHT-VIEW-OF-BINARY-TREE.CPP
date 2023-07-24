#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<pair<int, Node *>> q;
        map<int, int> m;
        // q --> {horizontal_level, Node*}  and m --> {horizontal_level , Node-> value}

        q.push(make_pair(0, root)); // root is at horizontal level 0
        while (!q.empty())
        {
            auto x = q.front();
            int horizontal = x.first;
            q.pop();

            // if we have not stored any node for the current horizontal level then update the map
            if (m.count(horizontal) == 0)
            {
                m[horizontal] = x.second->data;
            }

            // if left node is present --> then store it in queue by increasing the current horizontal level
            if (x.second->right != NULL)
            {
                q.push(make_pair(horizontal + 1, x.second->right));
            }

            // if right node is present --> then store it in queue by increasing the current horizontal level
            if (x.second->left != NULL)
            {
                q.push(make_pair(horizontal + 1, x.second->left));
            }
        }

        // now we have only one element stored in the map for each horizontal level and its the first element from left
        for (auto &&i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};