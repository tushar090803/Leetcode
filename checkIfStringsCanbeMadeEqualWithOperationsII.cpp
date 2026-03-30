#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s11,s12,s21,s22;
        for(int i=0;i<s1.size();i++){
           if(i&1){
            s12+=s1[i];
            s22+=s2[i];
           } 
           else{
            s11+=s1[i];
            s21+=s2[i];
           }
        }
        sort(s11.begin(),s11.end());
        sort(s12.begin(),s12.end());
        sort(s21.begin(),s21.end());
        sort(s22.begin(),s22.end());
        return s11==s21&&s12==s22;
    }
};