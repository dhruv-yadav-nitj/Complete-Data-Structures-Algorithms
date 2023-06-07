#include <bits/stdc++.h>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

// time comeplexity : O(N  + 2E) --> N : no of nodes and E :no of edges
// space complexity : O(N)

class Solution
{
public:
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here

        // we need : a queue and a visited array
        int isVisited[V] = {0};
        queue<pair<int, int>> q; // since the graph is 0-based indexing and the queue would store source node and the parent node

        // since the graph can have different part which are actually not connected to each other (we call them as sub parts of graph) , we would be using for loop to iterate over these graphs

        for (int i = 0; i < V; i++)
        {
            if (!isVisited[i])
            {

                q.push({i, -1});
                isVisited[i] = 1;

                while (!q.empty())
                {
                    auto graph_node = q.front();
                    int source_node = graph_node.first, parent_node = graph_node.second;
                    q.pop();
                    for (auto x : adj[source_node])
                    {
                        // now source node would act as parent node for its further adjacencies
                        if (x != parent_node)
                        { // since its a undirected graph --> two nodes would be interconnected to each other and agar hme kisi         node se aage badhna hain to hm aisa to nahi krenge na ki jis node se is node tk aaye the waapis whi chale jaae aise to queue        mein hi ghumte rh jaaenge

                            if (isVisited[x])
                            {
                                return 1;
                            }

                            q.push({x, source_node}); // now source node would act as parent node for its further adjacencies
                            isVisited[x] = true;
                        }
                    }
                }
            }
        }

        return false;
    }
};