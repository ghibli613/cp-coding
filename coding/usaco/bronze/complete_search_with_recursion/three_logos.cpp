#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int max_check = 0;
    vector<array<int, 2>> logos(3);
    for(int i = 'A'; i <= 'C'; i++)
    {    
        cin >> logos[i - 65][0] >> logos[i - 65][1];
        max_check = max(max_check, logos[i - 65][0]);
        max_check = max(max_check, logos[i - 65][1]);
    }
    int cnt = 0;
    for(int i = 'A'; i <= 'C'; i++)
        if(logos[i - 65][0] == max_check || logos[i - 65][1] == max_check) cnt++;

    if(cnt == 2)
    {
        cout << -1;
        return;
    }
    else if(cnt == 3)
    {
        array<int, 3> tmp;
        int side = 0;
        for(int i = 'A'; i <= 'C'; i++)
            if(logos[i - 65][0] == max_check)
            {
                side += logos[i-65][1];
                tmp[i - 65] = logos[i-65][1];
            }
            else 
            {
                side += logos[i-65][0];
                tmp[i - 65] = logos[i-65][0];
            }

        if(side == max_check) 
        {
            cout << max_check << '\n';
            for(char i = 'A'; i <= 'C'; i++)
                for(int j = 0; j < tmp[i - 65]; j++)
                {
                    for(int t = 0; t < max_check; t++)
                        cout << i;
                    cout << '\n';
                }
        }
        else 
        {
            cout << -1;
            return;
        }
    }
    else
    {
        vector<char> a;
        char flag = 0;
        int side1 = 0;
        for(char i = 'A'; i <= 'C'; i++)
            if(logos[i - 65][0] == max_check) 
            {
                flag = i;
                side1 = logos[i - 65][1];
            }
            else if(logos[i - 65][1] == max_check) 
            {
                flag = i;
                side1 = logos[i - 65][0];
            }
            else a.push_back(i);

        bool check = false;
        map<char, int> my_map;
        for(char i : a)
        {
            if(logos[i-65][0] + side1 == max_check) my_map[i] = logos[i-65][1];
            else if(logos[i-65][1] + side1 == max_check) my_map[i] = logos[i-65][0];
            else
            {
                check = true;
                break;
            }
        }
        if(my_map[a[0]] + my_map[a[1]] != max_check) check = true;

        if(check)
        {
            cout << -1;
            return;
        }
        cout << max_check << '\n';
        for(int i = 0; i < side1; i++)
        {
            for(int j = 0; j < max_check; j++)
                cout << flag;
            cout << '\n';
        }
        
        for(int i = 0; i < max_check - side1; i++)
        {
            for(pair<char, int> j : my_map)
                for(int t = 0; t < j.second; t++)
                    cout << j.first;
            
            cout << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}