#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h,
                                      string d) {
        set<vector<int>> st;
        int n = p.size(),idx=0;
        for (int i = 0; i < n; i++) {
            st.insert({p[i], h[i], (d[i] == 'L' ? 0 : 1),idx++});
        }
        stack<vector<int>> s;
        for (vector<int>it:st) {
        int po= it[0],hi=it[1],di=it[2],id=it[3];
            while (!s.empty() &&s.top()[0] == 1 && di == 0) {
                if (hi <= s.top()[1]) {
                    if (hi == s.top()[1])
                        s.pop();
                    else {
                        int v1 = s.top()[1] - 1,idd=s.top()[2];
                        s.pop();
                        s.push({1, v1,idd});    
                    }
                    hi = 0;
                    break;
                } else {
                    s.pop();
                    hi--;
                }
            }
            if (hi != 0)
                s.push({di, hi,id});
        }
        vector<pair<int,int>> a;
        while (!s.empty()) {
            a.push_back({s.top()[1],s.top()[2]});
            s.pop();
        }
        sort(a.begin(), a.end(),[](pair<int,int>x,pair<int,int>y){
            return y.second>x.second;
        });
        vector<int>ans;
        for(pair<int,int>p:a){
            ans.push_back(p.first);
        }
        return ans;
    }
};