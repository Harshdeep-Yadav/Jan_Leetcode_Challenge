    class Solution
    {
    public:
        pair<int, int> coordinates(int x, int n)
        { // for finding the coordinates of row and column

            int r = n - (x - 1) / n - 1;
            int c = (x - 1) % n;
            if (r % 2 == n % 2)
                return {r, n - c - 1};
            return {r, c};
        }

        int snakesAndLadders(vector<vector<int>> &board)
        {
            int n = board.size();
            int steps = 0;
            queue<int> q;
            q.push(1);
            vector<vector<bool>> vis(n, vector<bool>(n));

            vis[n - 1][0] = true; // src node i.e :- 1

            while (!q.empty())
            {

                int qsize = q.size();

                for (int i = 0; i < qsize; i++)
                {

                    int node = q.front();

                    if (node == n * n)
                    { // n*n is desitination 36
                        return steps;
                    }

                    q.pop();

                    for (int j = 1; j <= 6; j++)
                    {
                        if (node + j > n * n)
                        { // out of the grid
                            break;
                        }

                        pair<int, int> p = coordinates(node + j, n);

                        if (vis[p.first][p.second])
                        {
                            continue;
                        }

                        vis[p.first][p.second] = true;

                        if (board[p.first][p.second] != -1)
                        {
                            q.push(board[p.first][p.second]);
                        }
                        else
                        {
                            q.push(j + node);
                        }
                    }
                }
                steps++;
            }
            return -1;
        }
    };