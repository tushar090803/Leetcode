#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row, col;
    vector<vector<vector<int>>> dp;
    int f(vector<vector<int>>& coins, int i, int j, int k) {
        if (i == row - 1 && j == col - 1) {
            if (coins[i][j] > 0)
                return coins[i][j];
            return k > 0 ? 0 : coins[i][j];
        }
        if(dp[i][j][k]!=INT_MIN)return dp[i][j][k];
        int ans = -1e9;
        if (coins[i][j] >= 0) {
            if (i + 1 < row)
                ans = coins[i][j] + f(coins, i + 1, j, k);
            if (j + 1 < col)
                ans = max(ans, coins[i][j] + f(coins, i, j + 1, k));
        } else {
            if (k > 0) {
                if (i + 1 < row)
                    ans = f(coins, i + 1, j, k - 1);
                if (j + 1 < col)
                    ans = max(ans, f(coins, i, j + 1, k - 1));
            }
            if (i + 1 < row)
                ans = max(ans,coins[i][j] + f(coins, i + 1, j, k));
            if (j + 1 < col)
                ans = max(ans, coins[i][j] + f(coins, i, j + 1, k));
        }
        return dp[i][j][k]=ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        row = coins.size(), col = coins[0].size();
        dp.resize(row, vector<vector<int>>(col, vector<int>(3, INT_MIN)));
        return f(coins, 0, 0, 2);
    }
};