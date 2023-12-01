// Longest repeating subsequence 

#include <bits/stdc++.h>
using namespace std;

string LongRepeatingSubsequence(string x, int n){
    int dp[n+1][n+1];
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==x[j-1] && i!=j){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int i=n, j=n;
    string ans = "";
    
    while(i>0 && j>0){
        if(x[i-1]==x[j-1] && i!=j){
            ans+=x[i-1];
            i--;j--;
        } else {
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            } else {
                j--;
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main(){
    string x = "AABEBCDD";
    
    cout << LongRepeatingSubsequence(x, x.size());
    return 0;
}
