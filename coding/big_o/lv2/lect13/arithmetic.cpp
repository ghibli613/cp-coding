#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int flag;

int ch(string s, int base)
{
    long long sum = 0;

    for (int i = 0; i < (int)s.size(); i++)
    {
        sum = s[i] - '0' + sum * base;
        if (s[i] - '0' >= base)
            flag = 1;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string A, B, C;
        string tmp;
        cin >> A;
        cin >> tmp;
        cin >> B;
        cin >> tmp;
        cin >> C;

        if (A + B == C)
        {
            bool valid = true;
            for (int i = 0; i < (int)C.size(); i++)
                if (C[i] != '1')
                {
                    valid = false;
                    break;
                }

            if (valid)
            {
                cout << 1 << '\n';
                continue;
            }
        }

        bool can_find = false;
        for (int i = 2; i <= 20; i++)
        {
            flag = 0;
            int a = ch(A, i), b = ch(B, i), c = ch(C, i);
            if (a + b == c && flag == 0)
            {
                cout << i << '\n';
                can_find = true;
                break;
            }
        }

        if (!can_find)
            cout << 0 << '\n';
    }
    return 0;
}