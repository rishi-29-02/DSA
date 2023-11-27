// Print the shortest common subsequence

#include <bits/stdc++.h>
using namespace std;

string shcomsup(string x, string y) {
    int n = x.size(), m=y.size();
    int dp[n+1][m+1];
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int i=n, j=m;
    string lcs = "";
    
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            lcs+=x[i-1];
            i--;j--;
        } else {
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            } else{
                j--;
            }
        }
    }
    
    reverse(lcs.begin(), lcs.end());
    string s = x+y;
    int k=0;
    string ans="";
    for(int i=0;i<s.size();i++){
        if(k<lcs.size() && s[i]==lcs[k]){
            k++;
        } else {
            ans+=s[i];
        }
    }
    
    return ans;
}

int main(){
    string x = "geek";
    string y = "eke";
    
    cout << shcomsup(x, y);
    
    return 0;
}
