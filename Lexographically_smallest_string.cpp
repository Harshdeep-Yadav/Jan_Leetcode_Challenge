class Solution
{
public:
    char dfsfindminChar(unordered_map<char, vector<char>> &adj, char cur_ch, vector<int> &vis)
    {
        vis[cur_ch - 'a'] = 1;

        char minChar = cur_ch;

        for (char &it : adj[cur_ch])
        {
            if (!vis[it - 'a'])
            {
                minChar = min(minChar, dfsfindminChar(adj, it, vis));
            }
        }
        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string base)
    {
        int n = base.size();
        int m = s1.size();

        unordered_map<char, vector<char>> adj;

        //         graph making
        for (int i = 0; i < m; i++)
        {
            //          source and adjecents
            char u = s1[i];
            char v = s2[i];

            //          both can interchange between them
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string ans;

        for (int i = 0; i < n; i++)
        {
            char ch = base[i];

            vector<int> vis(26, 0);

            char minchar = dfsfindminChar(adj, ch, vis);

            ans.push_back(minchar);
        }

        return ans;
    }
};
