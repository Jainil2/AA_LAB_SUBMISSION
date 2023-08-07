#include <bits/stdc++.h>
using namespace std;
#define V 6
bool bfs(int Rg[V][V], int s, int t, int P[])
{
    int visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    P[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++)
        {
            if (Rg[u][v] > 0 && visited[v] == 0)
            {
                if (v == t)
                {
                    P[v] = u;
                    return true;
                }
                P[v] = u;
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    return false;
}
int Max_flow(int G[V][V], int t, int s)
{
    int u, v;
    int max_flow = 0;
    int Rg[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            Rg[i][j] = G[i][j];
        }
    }

    int P[V];
    while (bfs(Rg, s, t, P))
    {
        int flow = INT_MAX;
        for (int v = t; v != s; v = P[v])
        {
            u = P[v];
            flow = min(flow, Rg[u][v]);
        }
        for (int v = t; v != s; v = P[v])
        {
            u = P[v];
            Rg[u][v] -= flow;
            Rg[v][u] -= flow;
        }
        max_flow += flow;
    }
    return max_flow;
}
int main()
{
    int G[6][6] = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0}, {0, 4, 0, 0, 14, 0}, {0, 0, 9, 0, 0, 20}, {0, 0, 0, 7, 0, 4}, {0, 0, 0, 0, 0, 0}};
    int t = 5;
    int s = 0;
    int result = Max_flow(G, t, s);
    cout << result << endl;
    return 0;
}
