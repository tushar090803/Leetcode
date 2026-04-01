#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    ll totalsum = 0;
    bool normal(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                totalsum += grid[i][j];
            }
        }
        ll sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                sum += grid[i][j];
            }
            if (totalsum - sum == sum)
                return true;
        }
        sum = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            for (int i = 0; i < grid.size(); i++) {
                sum += grid[i][j];
            }
            if (totalsum - sum == sum)
                return true;
        }
        return false;
    }

    bool f1(vector<vector<int>>& grid) {
        map<ll, ll> mp, mp1, mp2;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                mp[grid[i][j]]++, mp2[grid[i][j]]++;
            }
        }
        ll sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                sum += grid[i][j];
                mp2[grid[i][j]]--;
                if (mp2[grid[i][j]] == 0)
                    mp2.erase(grid[i][j]);
                mp1[grid[i][j]]++;
            }
            if (sum < totalsum - sum) {
                if (mp2.count(totalsum - 2 * sum)){
                    return true;
                }
            } else {
                if (mp1.count(2 * sum - totalsum)){
                    return true;
                }
            }
        }
        sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            sum += grid[i][0];
        }
        int s = totalsum - sum;
        if (sum == (s - grid[0][1]))
            return true;
        else if (sum == (s - grid[grid.size() - 1][1]))
            return true;
        else if ((sum - grid[0][0]) == s)
            return true;
        else if ((sum - grid[grid.size() - 1][0]) == s)
            return true;
        return false;
    }
    bool f2(vector<vector<int>>& grid) {
        map<int, int> mp, mp1, mp2;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++)
                mp[grid[i][j]]++, mp2[grid[i][j]]++;
        }
        ll sum = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            for (int i = 0; i < grid.size(); i++) {
                sum += grid[i][j];
                mp2[grid[i][j]]--;
                if (mp2[grid[i][j]] == 0)
                    mp2.erase(grid[i][j]);
                mp1[grid[i][j]]++;
            }
            if (sum < totalsum - sum) {
                if (mp2.count(totalsum - 2 * sum)){
                    return true;
                }
            } else {
                if (mp1.count(2 * sum - totalsum)){
                    return true;
                }
            }
        }
        sum = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            sum += grid[0][i];
        }
        int s = totalsum - sum;
        if (sum == (s - grid[1][0]))
            return true;
        else if (sum == (s - grid[1][grid[0].size() - 1]))
            return true;
        else if ((sum - grid[0][0]) == s)
            return true;
        else if ((sum - grid[0][grid[0].size() - 1]) == s)
            return true;
        return false;
    }
    bool f3(vector<vector<int>>& grid) {
        ll sum = 0, s = totalsum;
        for (int i = 0; i < grid[0].size(); i++) {
            sum += grid[0][i];
            s -= grid[0][i];
            if ((sum - grid[0][i]) == s)
                return true;
            if ((sum - grid[0][0]) == s)
                return true;
            else if (sum == (s - grid[0][grid[0].size() - 1]))
                return true;
        }
        return false;
    }
    bool f4(vector<vector<int>>& grid) {
        ll sum = 0, s = totalsum;
        for (int i = 0; i < grid.size(); i++) {
            sum += grid[i][0];
            s -= grid[i][0];
            if ((sum - grid[i][0]) == s)
                return true;
            if ((sum - grid[0][0]) == s)
                return true;
            else if (sum == (s - grid[grid.size() - 1][0]))
                return true;
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (normal(grid))
            return true;
        if (!(grid.size() == 2 && grid[0].size() == 2) &&
            (grid.size() <= 2 || grid[0].size() <= 2)) {
            cout << 'b';
            if (grid.size() > 2 && grid[0].size() == 2) {
                return f1(grid);
            } else if (grid[0].size() > 2 && grid.size() == 2) {
                return f2(grid);
            } else if (grid.size() == 1)
                return f3(grid);
            return f4(grid);
        } else {
            map<int, int> mp, mp1, mp2;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++)
                    mp[grid[i][j]]++, mp2[grid[i][j]]++;
            }
            ll sum = 0;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    sum += grid[i][j];
                    mp2[grid[i][j]]--;
                    if (mp2[grid[i][j]] == 0)
                        mp2.erase(grid[i][j]);
                    mp1[grid[i][j]]++;
                }
                if (i == 0) {
                    if ((sum - grid[0][0]) == totalsum - sum)
                        return true;
                    else if ((sum - grid[0][grid[0].size() - 1]) ==
                             totalsum - sum)
                        return true;
                } else if (i == grid.size() - 1) {
                    if ((sum - grid[i][0]) == totalsum - sum)
                        return true;
                    else if ((sum - grid[i][grid[0].size() - 1]) ==
                             totalsum - sum)
                        return true;
                }
                if (i < grid.size() - 1 && sum < totalsum - sum) {
                    if (mp2.count(totalsum - 2 * sum))
                        return true;
                } else if (i > 0) {
                    if (mp1.count(2 * sum - totalsum))
                        return true;
                }
            }
            sum = 0;
            mp1.clear();
            mp2 = mp;
            for (int j = 0; j < grid[0].size(); j++) {
                for (int i = 0; i < grid.size(); i++) {
                    sum += grid[i][j];
                    mp2[grid[i][j]]--;
                    if (mp2[grid[i][j]] == 0)
                        mp2.erase(grid[i][j]);
                    mp1[grid[i][j]]++;
                }
                if (j == 0) {
                    if ((sum - grid[0][0]) == totalsum - sum)
                        return true;
                    else if ((sum - grid[grid.size() - 1][0]) == totalsum - sum)
                        return true;
                } else if (j == grid[0].size() - 1) {
                    if ((sum - grid[0][j]) == totalsum - sum)
                        return true;
                    else if ((sum - grid[grid.size() - 1][j]) == totalsum - sum)
                        return true;
                }
                if (j < grid[0].size() - 1 && sum < totalsum - sum) {
                    if (mp2.count(totalsum - 2 * sum))
                        return true;
                } else if (j > 0) {
                    if (mp1.count(2 * sum - totalsum))
                        return true;
                }
            }
        }
        return false;
    }
};