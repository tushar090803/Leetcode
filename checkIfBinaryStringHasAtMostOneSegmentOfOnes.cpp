#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int f=false;
        int i=0;
        while(i<s.size()){
            if(s[i]=='1'&&f)return false;
            while(i<s.size()&&s[i]=='1'){
                i++;
                f=true;
            }
            i++;
        }
        return true;
    }
};