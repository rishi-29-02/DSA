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

int main(){
    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = sizeof(prices)/sizeof(prices[0]);
    
    cout << f(0, 1, 2, prices, n);
    return 0;
}
