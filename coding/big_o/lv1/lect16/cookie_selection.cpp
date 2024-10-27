#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void add(int val)
{
    int rightVal = minHeap.top();
    if (rightVal < val)
    {
        minHeap.push(val);
    }
    else
        maxHeap.push(val);
}

void makeBalance()
{
    while (maxHeap.size() > minHeap.size())
    {
        int top = maxHeap.top();
        maxHeap.pop();
        minHeap.push(top);
    }
    while (minHeap.size() > maxHeap.size() + 1)
    {
        int top = minHeap.top();
        minHeap.pop();
        maxHeap.push(top);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    minHeap.push(300000000);
    maxHeap.push(0);
    string x;
    int num = 0, num_ = 0;
    while (cin >> x)
    {
        if (x != "#")
        {
            int val = stoi(x);
            add(val);
            num++;
        }
        else
        {
            cout << minHeap.top() << '\n';
            minHeap.pop();
            num_++;
        }
        makeBalance();
    }

    return 0;
}