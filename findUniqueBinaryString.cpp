#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<int>st;
        for(string s:nums){
            int num=0;
            int i=0;
            while(i<s.size()){
                num<<=1;
                num=num|(s[i]-'0');
                i++;
            }
            st.insert(num);
        }
        for(int i=0;i<(1<<(nums[0].size()));i++){
            if(!st.count(i)){
                cout<<"i"<<i;
                string s="";
                int t=i;
                while(t){
                    int bit=t&1;
                    s+=(bit+'0');
                    t>>=1;
                }
                reverse(s.begin(),s.end());
                while(s.size()<nums[0].size())s="0"+s;
                return s;
            }
        }
        return "";
    }
};