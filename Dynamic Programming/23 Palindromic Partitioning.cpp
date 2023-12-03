// Palindromic Partitioning 
// Minimum number of partitions to make each substring palindrome

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool ispalindrome(string s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        else {
            i++;j--;
        }
    }
    return true;
}

int solve(string s, int i, int j){
    if(i>=j) return 0;
    if(ispalindrome(s, i, j)) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans = INT_MAX;
    
    for(int k=i;k<j;k++){
        int left, right;
        
        if(dp[i][k]!=-1) left=dp[i][k];
        else left = solve(s, i, k);
        
        if(dp[k+1][j]!=-1) right=dp[k+1][j];
        else right = solve(s, k+1, j);
        
        int tmpans = left + right + 1;
        
        ans = min(tmpans, ans);
    }
    
    return dp[i][j]=ans;
}

int main(){
    string s = "aabcc";
    
    int i=0;
    int j = s.size()-1;
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(s, i, j);
    
    return 0;
}
