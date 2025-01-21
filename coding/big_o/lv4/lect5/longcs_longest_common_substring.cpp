#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_DIGIT = 256;

void countingSort(vector<int>& SA, vector<int>& RA, int k = 0)
{
    int n = SA.size();
    vector<int> cnt(max(MAX_DIGIT, n), 0);

    for(int i = 0; i < n; i++)
    {
        if(i + k < n)
            cnt[RA[i + k]]++;
        else
            cnt[0]++;
    }
    for(int i = 1; i < (int)cnt.size(); i++)
        cnt[i] += cnt[i - 1];
    vector<int> tempSA(n);
    for(int i = n - 1; i >= 0; i--)
        if(SA[i] + k < n)
            tempSA[--cnt[RA[SA[i] + k]]] = SA[i];
        else
            tempSA[--cnt[0]] = SA[i];
    SA = tempSA;
}

vector<int> constructSA(string s)
{
    int n = s.length();
    vector<int> SA(n);
    vector<int> RA(n);
    vector<int> tempRA(n);

    for(int i = 0; i < n; i++)
    {
        RA[i] = s[i];
        SA[i] = i;
    }
    
    for(int step = 1; step < n; step <<= 1)
    {
        countingSort(SA, RA, step);
        countingSort(SA, RA, 0);
        
        tempRA[SA[0]] = 0;
        for(int i = 1; i < n; i++)
        {
            // cout << SA[i] << ' ' << SA[i - 1] << endl;
            if(RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + step] == RA[SA[i - 1] + step])
                tempRA[SA[i]] = tempRA[SA[i - 1]];
            else
                tempRA[SA[i]] = tempRA[SA[i - 1]] + 1;
        }
        RA = tempRA;
        if(RA[SA[n - 1]] == n - 1) break;
    }
    return SA;
}

vector<int> computeLCP(const string& s, const vector<int>& SA)
{
    int n = SA.size();
    vector<int> LCP(n), PLCP(n), c(n, 0);

    for(int i = 0; i < n; i++)
        c[SA[i]] = i;
    int k = 0;
    for(int j, i = 0; i < n - 1; i++)
    {
        j = SA[c[i] - 1];
        k = max(k - 1, 0);
        while (s[i + k] == s[j + k]) k++;
        PLCP[i] = k;
    }

    for(int i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];

    return LCP;
}

void solve()
{
    int sz; cin >> sz;
    string tot;
    for(int i = 0; i < sz; i++)
    {
        string tmp; cin >> tmp;
        tot += tmp + "$";
    }
    tot.pop_back();
    tot.push_back('#');
    if(sz == 1)
    {
        cout << tot.size() - 1 << '\n';
        return;
    }
    int n = (int)tot.size();
    vector<int> mark(n, -1), taken(n);
    int visID = 0;
    for(int i = 0; i < n; i++)
    {
        if(tot[i] != '$')
            mark[i] = visID;
        else 
            visID++;
    }
    vector<int> SA = constructSA(tot);
    vector<int> LCP = computeLCP(tot, SA);

    int ans = 0;
    multiset<int> s;
    for(int i = sz, j = sz, cnt = 0; i < n; i++)
    {
        if(cnt == sz)
        {
            if(j < n)
            {
                s.insert(LCP[j]);
                if(!taken[mark[SA[j]]])
                    cnt++;
                taken[mark[SA[j]]]++;
                j++;
            }
            else
                break;
        }
        else
        {
            s.erase(s.find(LCP[i]));
            ans = max(ans, *s.begin());
            taken[mark[SA[i]]]--;
            if(!taken[mark[SA[i]]])
                cnt--;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}