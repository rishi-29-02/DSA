// Buy and Sell Stock II (Infinite trans. allowed)

// Input: prices[] = {7, 1, 5, 3, 6, 4} 
// Output: 7 (Max. Profit)

#include <bits/stdc++.h>
using namespace std;

int main(){
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices)/sizeof(prices[0]);
    
    int profit=0;
    for(int i=0;i<n-1;i++){
        if(prices[i]<prices[i+1]){
            profit+=prices[i+1]-prices[i];
        }
    }
    
    cout << profit;
    return 0;
}
