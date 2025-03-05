#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, row, column;
    cin >> n >> k >> row >> column;

    // Define possible directions for the knight's moves
    vector<pair<int, int>> directions = {
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    // Initialize the previous and current DP tables
    vector<vector<double>> prevDp(n, vector<double>(n, 0));
    vector<vector<double>> currDp(n, vector<double>(n, 0));

    // Set the probability of the starting cell to 1
    prevDp[row][column] = 1;

    // Iterate over the number of moves
    for (int moves = 1; moves <= k; moves++)
    {
        // Iterate over the cells on the chessboard
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                currDp[i][j] = 0;

                // Iterate over possible directions
                for (const pair<int, int> &direction : directions)
                {
                    int prevI = i - direction.first;
                    int prevJ = j - direction.second;

                    // Check if the previous cell is within the chessboard
                    if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n)
                    {
                        // Update the probability by adding the previous probability divided by 8
                        currDp[i][j] += prevDp[prevI][prevJ] / 8;
                    }
                }
            }
        }

        // Swap the previous and current DP tables
        prevDp.swap(currDp);
    }

    // Calculate the total probability by summing up the probabilities for all cells
    double totalProbability = 0;
    for (const vector<double> &row : prevDp)
    {
        for (const double &cell : row)
        {
            totalProbability += cell;
        }
    }

    cout << fixed << setprecision(6) << totalProbability;

    return 0;
}