#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<vector<int>>&grid,int x,int y,int len){
        int ans=grid[x][y];
        if(len==1)return ans;
        int i=1;
        int t1=x,t2=y;
        while(i<len){
            i++;
            x--;
            y++;
            ans+=grid[x][y];
        }
        x=t1,y=t2;
        i=1;
        while(i<len){
            i++;
            x++;
            y++;
            ans+=grid[x][y];
        }
        y=t2+2*(len-1);
        x=t1;
        i=2;
        ans+=grid[x][y];
        t1=x,t2=y;
        while(i<len){
            i++;
            x--;
            y--;
            ans+=grid[x][y];
        }
        x=t1,y=t2;
        i=2;
        while(i<len){
            i++;
            x++;
            y--;
            ans+=grid[x][y];
        }
        return ans;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int>pq;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int t=grid[0].size()-j;
                if(t&1)t=t/2+1;
                else t=t/2;
                int lim = min({i + 1, (int)grid.size() - i, t});
                for(int x=1;x<=lim;x++){
                    int temp=f(grid,i,j,x);
                    pq.push(temp);
                }
            }
        }
        vector<int>ans;
        while(ans.size()<3&&!pq.empty()){
            if(ans.empty()||ans.back()!=pq.top())ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};