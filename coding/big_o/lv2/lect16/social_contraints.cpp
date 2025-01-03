#include <bits/stdc++.h>
using namespace std;

int find(int p, int arr[])
{
    for (int i = 0; i < 8; i++)
    {
        if (arr[i] == p)
            return i;
    }
    return -1;
}

int main()
{
    int n, m;
    int constraints[20][3];
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < m; i++)
            cin >> constraints[i][0] >> constraints[i][1] >> constraints[i][2];

        int arr[8] = {0, 1, 2, 3, 4, 5, 6, 7};

        int ans = 0;
        do
        {
            bool check = true;
            for (int i = 0; i < m; i++)
            {
                int pos1 = find(constraints[i][0], arr);
                int pos2 = find(constraints[i][1], arr);
                if (constraints[i][2] > 0)
                {
                    if (abs(pos1 - pos2) > constraints[i][2])
                    {
                        check = false;
                        break;
                    }
                }
                if (constraints[i][2] < 0)
                {
                    if (abs(pos1 - pos2) < (-constraints[i][2]))
                    {
                        check = false;
                        break;
                    }
                }
            }
            if (check)
                ans++;
        } while (next_permutation(arr, arr + n));

        cout << ans << endl;
    }

    return 0;
}