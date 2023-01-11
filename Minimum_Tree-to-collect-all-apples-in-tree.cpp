class Solution
{
public:
    int dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &hasApple)
    {

        int tottime = 0;
        int childtime = 0;
        for (auto child : adj[node])
        {
            if (child == parent)
                continue;
            childtime = dfs(child, node, adj, hasApple);

            if (childtime || hasApple[child])
            {
                tottime += childtime + 2;
            }
        }
        return tottime;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, adj, hasApple);
    }
};