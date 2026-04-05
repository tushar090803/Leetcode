#include<bits/stdc++.h>
using namspace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int>v(4,0);
        for(char ch:moves){
            if(ch=='L')v[0]++;
            else if(ch=='R')v[1]++;
            else if(ch=='U')v[2]++;
            else v[3]++;
        }
        return v[0]==v[1]&&v[2]==v[3];
    }
};