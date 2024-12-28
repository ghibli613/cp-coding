#include <bits/stdc++.h>
using namespace std;

string s, n, sum;
vector<int> plusid, res;

string add(string a, string b)
{
    string result = "";
    while (a.length() < b.length())
        a = "0" + a;
    while (b.length() < a.length())
        b = "0" + b;
    int carry = 0;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        int tmp = a[i] - 48 + b[i] - 48 + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        result = (char)(tmp + 48) + result;
    }
    if (carry > 0)
        result = "1" + result;
    return result;
}

bool bigger(string const &a, string const &b)
{
    if (a.size() > b.size())
        return true;
    if (a.size() < b.size())
        return false;
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (a[i] > b[i])
            return true;
        if (a[i] < b[i])
            return false;
    }
    return true;
}

void Backtrack(int pos, string cur, string sum)
{
    cur.push_back(s[pos]);
    if (pos == (int)s.size() - 1)
    {
        sum = add(sum, cur);
        if (sum == n)
        {
            res = plusid;
        }
        return;
    }
    if (res.size() > 0 || bigger(sum, n))
    {
        return;
    }
    Backtrack(pos + 1, cur, sum);
    plusid.push_back(pos);
    Backtrack(pos + 1, "", add(sum, cur));
    plusid.pop_back();
    cur.pop_back();
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        res.clear();
        plusid.clear();
        cin >> s >> n;

        Backtrack(0, "", "");
        reverse(res.begin(), res.end());
        for (int i = 0; i < (int)s.size(); i++)
        {
            cout << s[i];
            if ((int)res.size() > 0 && i == res.back())
            {
                cout << '+';
                res.pop_back();
            }
        }
        cout << endl;
    }
}
