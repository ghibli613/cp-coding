#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1e5 + 10;
vector<int> graph[MAX];
int indegree[MAX];
vector<int> result;
int n, m;

bool kahn()
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        result.push_back(u);
        for(int i = 0; i < (int)graph[u].size(); i++)
        {
            indegree[graph[u][i]]--;
            if(indegree[graph[u][i]] == 0)
            {
                q.push(graph[u][i]);
            }
        }
    }

    return result.size() == n;
}

int main()
{
    cin >> n >> m;

    for(int u, v, i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    if(!kahn())
        cout << "Graph is not a DAG";
    else
    {
        for(int i = 0; i < n; i++)
            cout << result[i] << " ";
    }

    return 0;
}