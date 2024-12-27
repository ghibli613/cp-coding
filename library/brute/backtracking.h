void backtracking(vector<int>& curState, int i, int sum)
{
    if(sum == s)
    {
        if(curState.size() > result.size())
        {
            result = curState;
        }
        return;
    }
    if(i == n)
        return;
    for(int j = 0; j < i; j++)
        if(sum + a[j] <= s)
        {
            curState.push_back(a[j]);
            sum += a[j];
            backtracking(curState, j + 1, sum);
            sum -= a[j];
            curState.pop_back();
        }
}