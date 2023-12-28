// Min Window Substring 

#include <bits/stdc++.h>
using namespace std;

string minSub(string s, string sub){
    int i=0, j=0;
    int n = s.length();
    unordered_map<char, int> mp;
    for(auto it:sub) mp[it]++;
    int cnt=mp.size();
    
    int minLen = INT_MAX;
    int start = 0;
    
    while(j<n){
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0) cnt--;
        }
        
        if(cnt==0){
            while(cnt==0){
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1) {
                        cnt++;
                        if(j-i+1<minLen){
                            minLen = j-i+1;
                            start = i;
                        }
                    }
                }
                i++;
            }
        }
        j++;
    }
    if(minLen==INT_MAX) return "";
    return s.substr(start, minLen);
}

int main(){
    string s = "ADOBECODEBANC";
    string sub = "ABC";
    
    cout << minSub(s, sub);
    return 0;
}
