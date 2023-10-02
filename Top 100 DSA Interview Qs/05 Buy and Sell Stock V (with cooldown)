// Buy and Sell Stock V (with cooldown)

// Means immediately after the selling you can't buy the stock on the next day


// Recursion 
int f(int idx, int buy, vector<int> &prices){
    int n = prices.size();
    
    if(idx>=n) return 0;
    
    if(buy){
        return max(-prices[idx] + f(idx+1, 0, prices),
                        0 + f(idx+1, 1, prices));
    }
    return max(prices[idx] + f(idx+2, 1, prices),
                    0 + f(idx+1, 0, prices));
}

int maxProfit(vector<int>& prices) {
    return f(0, 1, prices);
}

// Memoized 
int f(int idx, int buy, vector<int> &prices
            vector<vector<int>> &dp){
    int n = prices.size();
    
    if(idx>=n) return 0;
    
    if(dp[idx][cap]!=-1){
        return dp[idx][cap];
    }
    
    if(buy){
        return dp[idx][cap] = max(-prices[idx] + f(idx+1, 0, prices),
                        0 + f(idx+1, 1, prices));
    }
    return dp[idx][cap] = max(prices[idx] + f(idx+2, 1, prices),
                    0 + f(idx+1, 0, prices));
}

int maxProfit(vector<int>& prices) {
    
    vector<vector<int>> dp(n, vector<int> (2, -1));
    return f(0, 1, prices, dp);
}

// Top-Down
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int> (2, 0));
    
    for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
            if(buy){
                dp[idx][buy] = max(-prices[idx] + dp[idx+1][0],
                                0 + dp[idx+1][1]);
            }
            else{
                dp[idx][buy] = max(prices[idx] + dp[idx+2][1],
                            0 + dp[idx+1][0]);
            }
        }
    }
    return dp[0][1];
}
