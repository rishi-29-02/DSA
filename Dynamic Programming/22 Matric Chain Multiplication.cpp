// Matrix chain Multiplication

#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int solve(int arr[], int i, int j){
    if(i>=j) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int tmpans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, tmpans);
    }
    return dp[i][j]=ans;
}

int main() {
    int arr[] = {10, 20, 30, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    memset(dp, -1, sizeof(dp));
    
    int i=1;
    int j=n-1;
    
    cout << solve(arr, i, j);
    
    return 0;
}
