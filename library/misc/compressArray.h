void compressArray(vector<int>& a, int n)
{
    vector<int> b;
    for(int i : a)
        b.push_back(i);
    sort(b.begin(), b.end());

    unordered_map<int, int> zipIdx;
    int newIdx = 1;
    for(int i = 0; i < n i++)
        if(i == 0 || b[i] != b[i - 1])
        {
            zipIdx[b[i]] = newIdx;
            newIdx++;
        }
    for(int i = 0; i < n; i++)
    {
        a[i] = zipIdx[a[i]];
    }
}