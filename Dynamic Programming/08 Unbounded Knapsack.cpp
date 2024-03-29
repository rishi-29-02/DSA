// unbounded Knapsack

#include <bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wt[], int W, int n){
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
            if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int val[] = {1, 30};
    int wt[] = {1, 50};
    int n = sizeof(val)/sizeof(val[0]);
    int W = 100;
    
    cout << knapsack(val, wt, W, n);
    return 0;
}
