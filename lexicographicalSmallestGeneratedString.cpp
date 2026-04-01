#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    unordered_set<int>st;
    bool chk(string& str2,int idx,string&word){
        int ret=-1;
        for(int i=0;i<n;i++){
            if(str2[i]!=word[idx+i]){
                return true;
            }
            if(st.count(i+idx))ret=i+idx;
        }
        if(ret!=-1){
            word[ret]='b';
            return true;
        }
        return false;
    }
    string generateString(string str1, string str2) {
        string word;
        n=str2.size(),m=str1.size();
        for(int i=0;i<m;i++){
            if(str1[i]=='T'){
                if(word.empty())word+=str2;
                else{
                    for(int idx=i;idx<i+n-1;idx++){
                        if(word[idx]=='@')word[idx]=str2[idx-i];
                        else if(word[idx]!=str2[idx-i])return "";
                    }
                    word+=str2[n-1];
                }
            }
            else{
                if(word.empty()){
                    for(int idx=0;idx<n;idx++)word+='@';
                }
                else word+='@';
            }
        }
        bool alla=true;
        for(char ch:str2){
            if(ch!='a'){
                alla=false;
                break;
            }
        }
        for(int i=0;i<word.size();i++){
            if(word[i]=='@'){
                st.insert(i);
                word[i]='a';
            }
        }
        for(int i=0;i<m;i++){
            if(str1[i]=='F')if(!chk(str2,i,word))return "";
        }
        return word;
    }
};