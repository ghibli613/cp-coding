#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<string> dir;
    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "pwd")
        {
            for (int j = 0; j < (int)dir.size(); j++)
            {
                cout << '/' << dir[j];
            }
            cout << '/' << '\n';
        }
        else
        {
            string directory;
            cin >> directory;
            if (directory[0] == '/')
            {
                dir.clear();
                directory = directory.substr(1);
            }
            stringstream inp(directory);
            string temp;
            while (getline(inp, temp, '/'))
            {
                if (temp == ".." && dir.size() > 0)
                {
                    dir.pop_back();
                }
                else
                {
                    dir.push_back(temp);
                }
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}