#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    int M=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        ll pro=1;
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=pro;
                pro=(pro*grid[i][j])%M;
            }
        }
        pro=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                ans[i][j]=(ans[i][j]*pro)%M;
                pro=(pro*grid[i][j])%M;
            }
        }
        return ans;
    }
};