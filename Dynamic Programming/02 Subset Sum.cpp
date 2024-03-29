// Check if the subset sum exists in the given array 

#include <bits/stdc++.h>
using namespace std;

bool knapsack(int arr[], int n, int W){
    bool dp[n+1][W+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0){
                dp[i][j] = false;
            }
            if(j==0){
                dp[i][j] = true;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else if(arr[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int sum = 60;
    cout << knapsack(arr, n, sum);
    return 0;
}
