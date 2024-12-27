#include <iostream>
#include <vector>
using namespace std;

const int MAX = 110;

int deg[MAX][MAX];
int n, m;
vector<int> result;

void findEulerPath(int u)
{
    for(int v = 0; v < n; v++)
    {
        if(deg[u][v] > 0)
        {
            deg[u][v]--;
            deg[v][u]--;
            findEulerPath(v);
        }
    }
    result.push_back(u);
}

int main()
{
    cin >> n >> m;

    for(int u, v, i = 0; i < m; i++)
    {
        cin >> u >> v;
        deg[u][v]++;
        deg[v][u]++;
    }

    findEulerPath(0);
    for(int v : result)
    {
        cout << v << " ";
    }
    return 0;
}