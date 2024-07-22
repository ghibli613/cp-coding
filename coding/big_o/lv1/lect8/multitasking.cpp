#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, int m)
{
    vector<vector<int>> calendar(1e6 + 2);
    vector<int> one_task_start(n), one_task_end(n);
    vector<int> multi_task_start(m), multi_task_end(m), inteval(m);
    for (int i = 0; i < n; i++)
        cin >> one_task_start[i] >> one_task_end[i];

    for (int i = 0; i < m; i++)
    {
        cin >> multi_task_start[i] >> multi_task_end[i] >> inteval[i];
        if (inteval[i] < multi_task_end[i] - multi_task_start[i])
        {
            cout << "CONFLICT\n";
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((int)calendar[one_task_start[i]].size() < 2 && (int)calendar[one_task_end[i]].size() < 2)
        {
            calendar[one_task_start[i]].push_back(i);
            calendar[one_task_end[i]].push_back(i);
        }
        else
        {
            cout << "CONFLICT\n";
            return;
        }
    }

    for (int i = 0; i < m; i++)
    {
        do
        {
            if ((int)calendar[multi_task_start[i]].size() < 2 && (int)calendar[multi_task_end[i]].size() < 2)
            {
                calendar[multi_task_start[i]].push_back(i);
                calendar[multi_task_end[i]].push_back(i);
            }
            else
            {
                cout << "CONFLICT\n";
                return;
            }

            multi_task_start[i] += inteval[i];
            multi_task_end[i] += inteval[i];
            if (multi_task_end[i] > 1e6)
                multi_task_end[i] = 1e6 + 1;
        } while (multi_task_start[i] <= 1e6);
    }
    // cout << calendar[10].size();
    int flag = -1;
    for (int i = 0; i <= 1e6; i++)
    {
        if (flag == -1 && calendar[i].size() == 2)
        {
            cout << "CONFLICT\n";
            return;
        }
        else if (flag == -1 && calendar[i].size() == 1)
        {
            flag = calendar[i][0];
        }
        else if (flag != -1 && calendar[i].size() == 2)
        {
            if (calendar[i][0] == flag)
                flag = calendar[i][1];
            else if (calendar[i][1] == flag)
                flag = calendar[i][0];
            else
            {
                cout << "CONFLICT\n";
                return;
            }
        }
        else if (flag != -1 && calendar[i].size() == 1)
        {
            if (calendar[i][0] == flag)
                flag = -1;
            else
            {
                cout << "CONFLICT\n";
                return;
            }
        }
        // cout << flag << ' ';
    }
    cout << "NO CONFLICT\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        solve(n, m);
    }

    return 0;
}