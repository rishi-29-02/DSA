// Min. No of insertion and deletion to convert string a to string b 

#include <bits/stdc++.h>
using namespace std;

void minNoInDe(string x, string y, int n, int m){
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
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout << "minNoIn : " << x.size()-dp[n][m] << endl;
    cout << "minNodel : " << y.size()-dp[n][m] << endl;
}

int main(){
    string x = "heap";
    string y = "pea";
    
    minNoInDe(x, y, x.size(), y.size());
    
    return 0;
}
