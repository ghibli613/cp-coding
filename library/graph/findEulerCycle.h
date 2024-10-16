void findEulerCycle()
{
    int u = -1, v = -1;
    bool isConnected = true, bad = false;

    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
            cnt += g[i][j];

        if(cnt % 2 == 1)
        {
            if(u == -1)
                u = i;
            else if(v == -1)
                v = i;
            else
            {
                bad = true;
                break;
            }
        }
    }

    if(bad)
    {
        cout << "Graph does not have Euler Path";
        return;
    }
    if(u != -1)
    {
        g[u][v]++; g[v][u]++;
        m++;
    }
    findEulerPath(0);
    if((int)result.size() != m + 1)
    {
        cout << "Graph does not have Euler Path";
        return;
    }
    if(u == -1)
    {
        cout << "Euler cycle: ";
        for(int v : result)
            cout << v << " ";
        return;
    }

    for(int i = 0; i < (int)result.size(); i++)
    {
        if((result[i] == u && result[i + 1] == v) || (result[i] == v && result[i + 1] == u))
        {
            for(int j = 1; j <= i; j++)
                result.push_back(result[j]);
            result.erase(result.begin(), result.begin() + i + 1);
            break;
        }
    }

    cout << "Euler Path: "
    for(int v : result)
        cout << v << " ";
}