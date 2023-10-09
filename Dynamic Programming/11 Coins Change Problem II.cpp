// Coins Change Problem II - Minimum number of Coins

#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int n, int W){
    int dp[n+1][W+1];
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(j==0) dp[i][j] = 0;
            if(i==0) dp[i][j] = INT_MAX-1;
        }
    }
    
    for(int j=1;j<W+1;j++){
        if(j%coins[0]){
            dp[1][j] = j/coins[0];
        }
        else{
            dp[1][j] = INT_MAX-1;
        }
    }
    
    for(int i=2;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(coins[i-1]<=j){
                dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            } else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main(){
    int coins[] = {1, 2, 3, 5};
    int n = sizeof(coins)/sizeof(coins[0]);
    
    int W=8;
    
    cout << minCoins(coins, n, W);
    return 0;
}
