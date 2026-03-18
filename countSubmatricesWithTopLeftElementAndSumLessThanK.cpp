#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll=long long;
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<ll>>prefix(rows,vector<ll>(cols));
        for(int i=0;i<cols;i++)prefix[0][i]=grid[0][i]+(i-1>=0?prefix[0][i-1]:0);
        for(int i=1;i<rows;i++){
            for(int j=0;j<cols;j++){
                prefix[i][j]=grid[i][j];
                if(j-1>=0)prefix[i][j]+=prefix[i][j-1];
            }
            for(int j=0;j<cols;j++){
                prefix[i][j]+=prefix[i-1][j];
            }
        }
        int ans=0;
        for(int j=0;j<cols;j++){
            for(int i=0;i<rows;i++){
                if(prefix[i][j]<=k)ans++;
                else break;
            }
        }
        return ans;
    }
};