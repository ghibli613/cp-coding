vector<vector<int>> graph;
int n, m;
vector<int> path;
vector<int> visited;

void findHamiltonPath(int u)
{
    if((int)path.size()== n)
    {
        bool hasCycle = false;
        for(int v : graph[u])
            if(v == path[0])
            {
                hasCycle = true;
                break;
            }
        if(hasCycle)
            cout << "found a Hamilton cycle";
        else
            cout << "found a Hamilton path";
        return;
    }

    for(int v : graph[u])
    {
        if(!visited[v])
        {
            visited[v] = true;
            path.push_back(v);
            findHamiltonPath(v);
            path.pop_back();
            visited[v] = false;
        }
    }
}