#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(string& s,char ch){
        int cnt=0;
        for(char c:s){
            if(c!=ch)cnt++;
            if(ch=='0')ch='1';
            else ch='0';
        }
        return cnt;
    }
    int minOperations(string s) {
        int ans=INT_MAX;
        ans=min(ans,f(s,'0'));
        ans=min(ans,f(s,'1'));
        return ans;
    }
};
