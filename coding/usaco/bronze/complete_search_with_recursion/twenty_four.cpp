#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int operation(int op, int num1, int num2)
{
    switch(op)
    {
        case 0:
            return num1 + num2;
        case 1:
            return num1 - num2;
        case 2:
            return num1 * num2;
        case 3:
            if(num2 == 0 || num1 % num2 != 0) return INT32_MIN;
            return num1 / num2;
    }
    return INT32_MIN;
}

void solve()
{
    int n; cin >> n;
    int ans;
    vector<int> hand(4);
    for(int i = 0; i < n; i++) 
    {
        ans = INT_MIN;
        for(int j = 0; j < 4; j++) cin >> hand[j];
        sort(hand.begin(), hand.end());
        do
        {
            for(int op1 = 0; op1 < 4; op1++)
                for(int op2 = 0; op2 < 4; op2++)
                    for(int op3 = 0; op3 < 4; op3++)
                    {
                        int first = operation(op1, hand[0], hand[1]);
                        if(first == INT32_MIN) continue;

                        int second = operation(op2, first, hand[2]);
                        if(second == INT32_MIN) continue;

                        int third = operation(op3, second, hand[3]);
                        if(third == INT32_MIN) continue;

                        if(third <= 24) ans = max(ans, third);
                    }

            for(int op1 = 0; op1 < 4; op1++)
                for(int op2 = 0; op2 < 4; op2++)
                    for(int op3 = 0; op3 < 4; op3++)
                    {
                        int first = operation(op1, hand[0], hand[1]);
                        if(first == INT32_MIN) continue;

                        int second = operation(op2, hand[2], hand[3]);
                        if(second == INT32_MIN) continue;

                        int third = operation(op3, first, second);
                        if(third == INT32_MIN) continue;

                        if(third <= 24) ans = max(ans, third);
                    }
        } while(next_permutation(hand.begin(), hand.end()));

        cout << ans << "\n";
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