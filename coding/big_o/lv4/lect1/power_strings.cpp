#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;

    while (cin >> s && s[0] != '.')
    {
        int i = 1;
        int subString = 0;
        int length = s.length();

        vector<int> lenSubString;
        lenSubString.push_back(1);
        for(int j = 2; j <= sqrt(length); j++)
            if(length % j == 0) lenSubString.push_back(j);
        
        lenSubString.push_back(length);

        while (i < length)
        {
            // While it is different the comparing then increase the substring.
            while (s[i] != s[i % lenSubString[subString]])
                ++subString;
            // Increase the index.
            ++i;
        }
        // Check the length of maximum substring.
        cout << length / lenSubString[subString] << '\n';
    }
    return 0;
}