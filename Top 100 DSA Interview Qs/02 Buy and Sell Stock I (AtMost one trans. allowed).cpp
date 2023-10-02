// Buy and Sell Stock I (AtMost one trans. allowed)

// Input: prices[] = {7, 1, 5, 3, 6, 4}
// Output: 5
// Explanation:
// The lowest price of the stock is on the 2nd day, i.e. price = 1. Starting from the 2nd day, the highest price of the stock is witnessed on the 5th day, i.e. price = 6. 
// Therefore, maximum possible profit = 6 – 1 = 5. 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int minp = 0;
    int ans = 0;
    
    for(int i=0;i<n;i++){
        if(arr[i]>arr[minp]){
            ans = max(ans, arr[i]-arr[minp]);
        }
        else{
            minp = i;
        }
    }
    
    cout << ans;
    return 0;
}
