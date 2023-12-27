// Max sum subarray of size k 

#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n, int k){
    int i=0, j=0;
    int sum=0;
    int ans = INT_MIN;
    while(j<n){
        sum+=arr[j];
        if((j-i+1)==k){
            ans = max(sum, ans);
            sum-=arr[i];
            i++;j++;
        } else {
            j++;
        }
    }
    return ans;
}

int main(){
    int arr[] = {1, 4, 3, 6, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    
    cout << maxSum(arr, n, k);
    
    return 0;
}
