#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

void solve()
{
    int N;
    cin >> N;
    vector<int> onestar(N), twostar(N);
    for (int j = 0; j < N; j++)
        cin >> onestar[j] >> twostar[j];
    
    int stars = 0;
    bool isDone = false;
    int turns = 0;
    while (true)
    {
        int maxone = -1;
        for (int k = 0; k < N; k++)
            if (twostar[k] <= stars && twostar[k] != -1 && (maxone == -1 || onestar[maxone] < onestar[k]))
                maxone = k;

        if (maxone != -1)
        {
            turns++;
            twostar[maxone] = -1;

            if (onestar[maxone] == -1)
                stars += 1;
            else
            {
                onestar[maxone] = -1;
                stars += 2;
            }
            continue;
        }

        int maxtwo = -1;
        for (int k = 0; k < N; k++)
            if (onestar[k] <= stars && onestar[k] != -1 && (maxtwo == -1 || twostar[maxtwo] < twostar[k] || twostar[k] == -1))
            {
                maxtwo = k;
                if (twostar[k] == -1)
                    break;
            }

        if (maxtwo != -1)
        {
            turns++;
            onestar[maxtwo] = -1;
            stars += 1;
            continue;
        }

        int score = 0;
        for (int k = 0; k < N; k++)
            score += onestar[k] + twostar[k];

        isDone = (score == -2 * N);
        break;
    }
    if (isDone)
        cout << turns << endl;
    else
        cout << "Too Bad" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}