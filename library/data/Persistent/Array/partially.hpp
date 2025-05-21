vector<vector<pair<int, int>>> arr;
int timestamp = 0;

void updateItem(int pos, int value)
{
    ++timestamp;
    arr[pos].push_back({timestamp, value});
}

int getItem(int pos, int time)
{
    auto node = upper_bound(
        arr[pos].begin(),
        arr[pos].end(),
        make_pair(time, INT_MAX)
    );
    return prev(node)->second;
}

void init(const vector<int>& a)
{
    int n = a.size();
    arr = vector<vector<pair<int, int>>>(n);
    timestamp = 0;
    for(int i = 0; i < n; i++)
        arr[i].push_back({timestamp, a[i]});
}