#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        set<int> s;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                s.insert(grid[i][j]);
                mp[grid[i][j]]++;
            }
        }

        for (int i = k - 1; i < row; i++) {
            if (i >= k) {
                for (int idx = 0; idx < k; idx++) {
                    mp[grid[i - k][idx]]--;
                    if (mp[grid[i - k][idx]] == 0) {
                        mp.erase(grid[i - k][idx]);
                        s.erase(grid[i - k][idx]);
                    }
                }
                for (int idx = 0; idx < k; idx++) {
                    mp[grid[i][idx]]++;
                    s.insert(grid[i][idx]);
                }
            }
            vector<int> tem;
            unordered_map<int, int> f = mp;
            set<int> st = s;
            for (int j = k - 1; j < col; j++) {
                if (j >= k) {
                    for (int idx = i-k+1; idx <= i; idx++) {
                        f[grid[idx][j - k]]--;
                        if (f[grid[idx][j - k]] == 0) {
                            f.erase(grid[idx][j - k]);
                            st.erase(grid[idx][j - k]);
                        }
                    }
                    for (int idx = i-k+1; idx <= i; idx++) {
                        f[grid[idx][j]]++;
                        st.insert(grid[idx][j]);
                    }
                }
                int mind=INT_MAX,temp=0;
                for(auto it=st.begin();it!=st.end();it++){
                    if(it==st.begin()){
                        temp=*it;
                    }
                    else{
                        mind=min(mind,*it-temp);
                        temp=*it;
                    }
                    // cout<<*it<<' ';
                }
                // cout<<'\n';
                if(mind==INT_MAX)mind=0;
                tem.push_back(mind);
            }
            ans.push_back(tem);
        }

        return ans;
    }
};