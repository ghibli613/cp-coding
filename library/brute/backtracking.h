void backtracking(vector<int>& curState, int i, int sum)
{
    if(best_length == curState.size())
    {
        return;
    }
    if(i == n)
    {
        best = curState;
        best_length = best.size();
        return;
    }
    for(int j = 0; j < i; j++)
    {
        curState.push_back(a[j]);
        backtracking(curState, j + 1, sum + a[j]);
        curState.pop_back();
    }
}