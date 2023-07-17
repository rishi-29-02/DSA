// Equal Sum Partition
// Check if the array can be partitioned into two subsets with equal sum 

#include <bits/stdc++.h>
using namespace std;

bool knapsack(int arr[], int n, int W){
    int dp[n+1][W+1];
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0){
                dp[i][j] = 0;
            }
            if(j==0){
                dp[i][j] = 1;
            }
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
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
    int arr[] = {1, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    if(sum%2==0){
        cout << knapsack(arr, n, sum/2);
    }
    else{
        cout << 0;
    }
    return 0;
}
