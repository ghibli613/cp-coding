#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 10;

vector<int> graph[MAX];
vector<int> low, num;
vector<bool> found;
stack<int> st;
int n, m;
int counter;

void dfs(int u)
{
    counter++;
    num[u] = low[u] = counter;
    st.push(u);

    for(int v : graph[u])
    {
        if(!found[v])
        {
            if(num[v] > 0)
                low[u] = min(low[u], num[v]);
            else
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }

    if(num[u] == low[u])
    {
        cout << "Found a SCC:";
        int v;
        do
        {
            v = st.top();
            st.pop();
            cout << " " << v;
            found[v] = true;
        } while(v != u);
        cout << "\n";
    }
}

void tarjan()
{
    counter = 0;
    low.assign(n + 1, 0);
    num.assign(n + 1, 0);
    found.assign(n + 1, false);
    st = stack<int>();

    for(int i = 1; i <= n; i++)
    {
        if(!num[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int u, v, i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    tarjan();

    return 0;
}