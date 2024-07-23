#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, int m)
{
    vector<bool> calender(1000001);
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        int start, end; cin >> start >> end;
        if(!flag)
        {
            if(end > 1000000) end = 1000000;
            for(int i = start; i < end; i++) 
            {
                if(calender[i])
                {
                    flag = true;
                    break;
                }
                calender[i] = true;
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        int s, e, r; cin >> s >> e >> r;
        while(!flag && s < 1000000)
        {
            if(e > 1000000) e = 1000000;
            for(int i = s; i < e; i++) 
            {
                if(calender[i])
                {
                    flag = true;
                    break;
                }
                calender[i] = true;
            }
            s += r;
            e += r;
        }
    }
    if(!flag) printf("NO CONFLICT\n");
    else printf("CONFLICT\n");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    
    while(true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        solve(n, m);
    }
        
    return 0;
}