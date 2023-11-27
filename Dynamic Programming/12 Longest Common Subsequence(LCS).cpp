// Longest common subsequence Recursive

#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, int n, string s2, int m){
    if(n==0 || m==0){
        return 0;
    }
    
    if(s1[n-1]==s2[m-1]){
        return 1+LCS(s1, n-1, s2, m-1);
    } else{
        return max(LCS(s1, n-1, s2, m), LCS(s1, n, s2, m-1));
    }
}

int main(){
    string s1 = "abcdefgh";
    string s2 = "abegh";
    
    cout << LCS(s1, s1.size(), s2, s2.size());
    return 0;
}

// Longest Common Subsequence (Memoized)

#include <bits/stdc++.h>
using namespace std;

static int t[1001][1001];

int LCS(string x, string y, int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    
    if(t[n][m]!=-1){
        return t[n][m];
    }
    
    if(x[n-1]==y[m-1]){
        return t[n][m] = 1+LCS(x, y, n-1, m-1);
    } else{
        return t[n][m] = max(LCS(x, y, n-1, m), LCS(x, y, n, m-1));
    }
}

int main(){
    string x = "abcegh";
    string y = "abfgh";
    
    memset(t, -1, sizeof(t));
    
    cout << LCS(x, y, x.size(), y.size());
    return 0;
}

// Longest Common Subsequence (LCS) (Top-Down)

#include <bits/stdc++.h>
using namespace std;

int LCS(string x, string y, int n, int m){
    int dp[n+1][m+1];
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[n][m];
}

int main(){
    string x = "abcdefg";
    string y = "abdgh";
    
    cout << LCS(x, y, x.size(), y.size());
    return 0;
}
