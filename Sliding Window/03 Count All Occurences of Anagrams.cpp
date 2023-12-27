// Count all the anagrams in the given string 

#include <bits/stdc++.h>
using namespace std;

int allAnagrams(string s, string sb){
    unordered_map<char, int> mp;
    for(auto it:sb){
        mp[it]++;
    }
    
    int ans=0;
    int i=0, j=0;
    int n = s.size();
    int k = sb.size();
    int cnt = mp.size();
    
    while(j<n){
        mp[s[j]]--;
        if(mp[s[j]]==0){
            mp.erase(s[j]);
            cnt--;
        }
        
        if(j-i+1==k){
            if(cnt==0){
                ans++;  
            }
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
            } else {
                mp[s[i]] =1;
                cnt++;
            }
            i++;j++;
        } else {
            j++;
        }
    }
    return ans;
}

int main() {
    string s = "aabaabaa";
    string sb = "aaba";
    
    cout << allAnagrams(s, sb); // 4
    return 0;
}
