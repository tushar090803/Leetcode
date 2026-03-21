#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> ans = grid;
        int z = k - 1 + x;
        for (int i = x; i < x + k; i++) {
            for (int j = y; j < y + k; j++) {
                ans[i][j] = grid[z][j];
            }
            z--;
        }

        return ans;
    }
};