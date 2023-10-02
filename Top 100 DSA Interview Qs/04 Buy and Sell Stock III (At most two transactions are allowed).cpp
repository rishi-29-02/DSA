// Buy and Sell Stock III (At most two transactions are allowed)

// Input: prices[] = {3, 3, 5, 0, 0, 3, 1, 4} 
// Output: 6 
// Explanation: 
// Buy on Day 4 and Sell at Day 6 => Profit = 3-0 = 3 
// Buy on Day 7 and Sell at Day 8 => Profit = 4-1 = 3 
// Therefore, Total Profit = 3 + 3 = 6

#include <bits/stdc++.h>
using namespace std;

// Recursion O(2^n)
int f(int idx, int buy, int cap, int prices[], int n){
    if(idx==n || cap==0) return 0;
    
    // Two choices :: buy or skip
    if(buy){
        return max(-prices[idx] + f(idx+1, 0, cap, prices, n),
                        0 + f(idx+1, 1, cap, prices, n));
    }
    // Two choices :: sell or skip
    else{
        return max(prices[idx] + f(idx+1, 1, cap-1, prices, n),
                        0 + f(idx+1, 0, cap, prices, n));
    }
}

// Memoization O(2^n)
int f(int idx, int buy, int cap, int prices[], int n,
            vector<vector<vector<int>>> &dp){
    if(idx==n || cap==0) return 0;
    
    if(dp[idx][buy][cap]!=-1){
        return dp[idx][buy][cap];
    }
    
    // Two choices :: buy or skip
    if(buy){
        return dp[idx][buy][cap] = max(-prices[idx] + f(idx+1, 0, cap, prices, n, dp),
                        0 + f(idx+1, 1, cap, prices, n, dp));
    }
    // Two choices :: sell or skip
    else{
        return dp[idx][buy][cap] = max(prices[idx] + f(idx+1, 1, cap-1, prices, n, dp),
                        0 + f(idx+1, 0, cap, prices, n, dp));
    }
}

// top-down
int f(int idx, int buy, int cap, int prices[], int n,
            vector<vector<vector<int>>> &dp){
    
    // Initialization
    // a. cap==0 
    for(int idx=0;idx<=n;idx++){
        for(int buy=0;buy<=1;buy++){
            dp[idx][buy][0] = 0;
        }
    }
    
    // b. idx==n 
    for(int buy=0;buy<=1;buy++){
        for(int cap=0;cap<=2;cap++){
            dp[n][buy][cap] = 0;
        }
    }
    
    for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                // Two choices :: buy or skip
                if(buy){
                    dp[idx][buy][cap] = max(-prices[idx] + dp[idx+1][0][cap],
                                    0 + dp[idx+1][1][cap]);
                }
                // Two choices :: sell or skip
                else{
                    dp[idx][buy][cap] = max(prices[idx] + dp[idx+1][1][cap-1],
                                    0 + dp[idx+1][0][cap]);
                }
            }
        }
    }
    
    return dp[0][1][2];
}

int main(){
    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = sizeof(prices)/sizeof(prices[0]);

    // Recursion
    //cout << f(0, 1, 2, prices, n, dp);
    
    // Memoization 
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    cout << f(0, 1, 2, prices, n, dp);
    
    // Top-down dp
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
    cout << f(0, 1, 2, prices, n, dp);

    // Optimized Top-down
    vector<vector<int>> after(2, vector<int> (3, 0));
    vector<vector<int>> curr(2, vector<int> (3, 0));
    
    for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                // Two choices :: buy or skip
                if(buy){
                    curr[buy][cap] = max(-prices[idx] + after[0][cap],
                                    0 + after[1][cap]);
                }
                // Two choices :: sell or skip
                else{
                    curr[buy][cap] = max(prices[idx] + after[1][cap-1],
                                    0 + after[0][cap]);
                }
            }
        }
        after = curr;
    }
    
    cout << curr[1][2];
    
    return 0;
}
