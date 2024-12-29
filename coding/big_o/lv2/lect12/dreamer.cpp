#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int a)
{
    if (a % 4 != 0)
        return false;
    if (a % 400 == 0)
        return true;
    if (a % 100 == 0)
        return false;
    return true;
}

bool isValidDate(int day, int month, int year)
{
    if (day == 0 || day > 31 || month == 0 || month > 12)
        return false;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return day <= 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return day <= 30;
    case 2:
        return day <= (isLeapYear(year) ? 29 : 28);
    default:
        return false;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> a(8);
        string d, m, y;
        cin >> d >> m >> y;
        a[0] = d[0] - '0';
        a[1] = d[1] - '0';
        a[2] = m[0] - '0';
        a[3] = m[1] - '0';
        a[4] = y[0] - '0';
        a[5] = y[1] - '0';
        a[6] = y[2] - '0';
        a[7] = y[3] - '0';

        int ret = 0;
        int D = 31, M = 12, Y = 9999;
        sort(a.begin(), a.end());
        do
        {
            int dd = a[0] * 10 + a[1];
            int mm = a[2] * 10 + a[3];
            int yy = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7];
            if (yy >= 2000 && isValidDate(dd, mm, yy))
            {
                ret++;
                // update smallest date until now
                if (yy == Y)
                {
                    if (mm == M)
                    {
                        if (dd < D)
                            D = dd;
                    }
                    else if (mm < M)
                    {
                        D = dd;
                        M = mm;
                    }
                }
                else if (yy < Y)
                {
                    Y = yy;
                    M = mm;
                    D = dd;
                }
            }
        } while (next_permutation(a.begin(), a.end()));

        if (ret > 0)
        {
            std::cout << ret << " ";
            if (D < 10)
                cout << 0 << D << " ";
            else
                cout << D << " ";
            if (M < 10)
                cout << 0 << M << " ";
            else
                cout << M << " ";
            cout << Y << '\n';
        }
        else
            std::cout << "0\n";
    }
}