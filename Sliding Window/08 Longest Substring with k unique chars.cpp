// Longest Substring with k unique characters

#include <bits/stdc++.h>
using namespace std;

int longSubk(string s, int n, int k){
    int i=0, j=0;
    unordered_map<char, int> mp;
    
    int ans = INT_MIN;
    
    while(j<n){
        mp[s[j]]++;
        if(mp.size()==k){
            ans = max(j-i+1, ans);
        } else if(mp.size()>k){
            while(mp.size()>k){
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
    string s = "abaccab";
    int n = s.length();
    int k=2;
    
    cout << longSubk(s, n, k);
    return 0;
}
