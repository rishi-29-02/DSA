// Rod cutting problem 

#include <bits/stdc++.h>
using namespace std;

int maxProfit(int price[], int len[], int W, int n){
    int dp[n+1][W+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(len[i-1]<=j){
                dp[i][j] = max(price[i-1]+dp[i][j-len[i-1]], dp[[i-1][j]);
            }
            else if(len[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int len[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(val)/sizeof(val[0]);
    
    int l = 8;
    cout << maxProfit(price, len, l, n);
    return 0;
}
