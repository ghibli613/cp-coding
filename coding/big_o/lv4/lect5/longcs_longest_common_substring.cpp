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
    int num_s; cin >> num_s;
    if(num_s == 1)
    {
        string s; cin >> s;
        cout << (int)s.size() << '\n';
        return;
    }

    string S;
    for(int i = 0; i < num_s; i++)
    {
        string tmp; cin >> tmp;
        S += tmp + "#";
    }
    S.pop_back();
    S += "!";

    vector<int> belong;
    int cnt = 0;
    for(int i = 0; i < (int)S.size(); i++)
    {
        if(S[i] == '#' || S[i] == '!')
        {
            belong.push_back(-1);
            cnt++;
        }
        else 
            belong.push_back(cnt);
    }

    cnt = 0;
    vector<int> count(num_s, 0);
    vector<int> SA = constructSA(S);
    vector<int> LCP = computeLCP(S, SA);
    int i = 0, ans = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    // for(int j = 0; j < (int)SA.size(); j++) cout << SA[j] << ' ';
    // cout << endl;
    // for(int j = 0; j < (int)SA.size(); j++) cout << LCP[j] << ' ';
    // cout << endl;
    // for(int j = 0; j < (int)SA.size(); j++) cout << belong[SA[j]] << ' ';
    // cout << endl;

    for(int j = 0; j < (int)SA.size(); j++)
    {
        if(belong[SA[j]] != -1)
        {
            if(count[belong[SA[j]]] == 0)
            {
                cnt++;
                count[belong[SA[j]]]++;
            }
            else
                count[belong[SA[j]]]++;

            heap.push({LCP[j], j});

            while(count[belong[SA[i]]] > 1)
            {
                count[belong[SA[i]]]--;
                i++;
            }
            while(!heap.empty() && heap.top().second <= i)
            {
                heap.pop();
            }
            if(cnt == num_s && !heap.empty())
                ans = max(heap.top().first, ans);
        }
        else
        {
            i++;
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