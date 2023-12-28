// Longest Substring without repeating characters 

#include <bits/stdc++.h>
using namespace std;

int longSub(string s, int n){
    int i=0, j=0;
    unordered_map<char, int> mp;
    
    int ans = INT_MIN;
    
    while(j<n){
        mp[s[j]]++;
        if((j-i+1)==mp.size()){
            ans = max(ans, j-i+1);
        } else if(j-i+1>mp.size()){
            while(i<j){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return ans;
}

int main(){
    string s = "abcabcbb"; // 3
    int n = s.size();
    
    cout << longSub(s, n);
    
    return 0;
}
