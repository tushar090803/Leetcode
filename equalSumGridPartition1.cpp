#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    using ll=long long;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll totalsum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                totalsum+=grid[i][j];
            }
        }
        ll sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
            }
            if(totalsum-sum==sum)return true;
        }
        sum=0;
        for(int j=0;j<grid[0].size();j++){
            for(int i=0;i<grid.size();i++){
                sum+=grid[i][j];
            }
            if(totalsum-sum==sum)return true;
        }
        return false;
    }
};