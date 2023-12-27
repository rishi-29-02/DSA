// Longest Substring with k unique Characters

#include <bits/stdc++.h>
using namespace std;

int longSub(string s, int n, int k){
    int i=0, j=0;
    unordered_map<char, int> mp;
    int maxi = INT_MIN;
    
    while(j<n){
        mp[s[j]]++;
        while(mp.size()>0 && mp.size()>k && i<j){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        
        if(mp.size()==k){
            maxi = max(maxi, j-i+1);
        }
        j++;
    }
    return maxi;
}

int main(){
    string s = "aabacbebebe"; // 7
    int k = 3;
    
    cout << longSub(s, s.length(), k);
    return 0;
}
