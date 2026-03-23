#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    int M = 1e9+7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(2)));

        dp[0][0][0] = dp[0][0][1] = grid[0][0];

        for(int i = 1; i < m; i++){
            dp[i][0][0] = dp[i-1][0][0] * grid[i][0];
            dp[i][0][1] = dp[i-1][0][1] * grid[i][0];
        }

        for(int j = 1; j < n; j++){
            dp[0][j][0] = dp[0][j-1][0] * grid[0][j];
            dp[0][j][1] = dp[0][j-1][1] * grid[0][j];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                ll val = grid[i][j];

                ll a = dp[i-1][j][0] * val;
                ll b = dp[i-1][j][1] * val;
                ll c = dp[i][j-1][0] * val;
                ll d = dp[i][j-1][1] * val;

                dp[i][j][0] = min({a, b, c, d});
                dp[i][j][1] = max({a, b, c, d});
            }
        }

        ll ans = dp[m-1][n-1][1];

        if(ans < 0) return -1;
        return ans % M;
    }
};