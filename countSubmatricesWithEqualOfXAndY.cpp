#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int cnt = 0;
        int chk = INT_MAX;
        vector<int> pre(grid[0].size(), 0);
        for (int i = 0; i < grid[0].size(); i++) {
            if (i > 0) {
                if (grid[0][i] == 'X') {
                    pre[i] = pre[i - 1] + 1;
                    chk = min(chk, i);
                } else if (grid[0][i] == 'Y') {
                    pre[i] = pre[i - 1] - 1;
                } else {
                    pre[i] = pre[i - 1];
                }
            } else {
                if (grid[0][i] == 'X') {
                    pre[i] = 1;
                    chk = 0;
                } else if (grid[0][i] == 'Y') {
                    pre[i] = -1;
                }
            }
            if (pre[i] == 0 && chk <= i) {
                cnt++;
            }
        }
        for (int i = 1; i < grid.size(); i++) {
            vector<int> temp(grid[0].size(), 0);
            for (int j = 0; j < grid[0].size(); j++) {
                if (j > 0) {
                    if (grid[i][j] == 'X') {
                        temp[j] = temp[j - 1] + 1;
                        chk = min(chk, j);
                    } else if (grid[i][j] == 'Y') {
                        temp[j] = temp[j - 1] - 1;
                    } else {
                        temp[j] = temp[j - 1];
                    }
                } else {
                    if (grid[i][j] == 'X') {
                        temp[j] = 1;
                        chk = 0;
                    } else if (grid[i][j] == 'Y') {
                        temp[j] = -1;
                    }
                }
                if (pre[j] + temp[j] == 0 && chk <= j) {
                    cnt++;
                }
                pre[j] += temp[j];
            }
        }
        return cnt;
    }
};