// Largest subarray of sum k 

#include <bits/stdc++.h>
using namespace std;

int largSub(int arr[], int n, int k){
    int i=0, j=0;
    int sum=0;
    int maxi = INT_MIN;
    
    while(j<n){
        sum+=arr[j];
        if(sum>k){
            while(sum>k && i<j){
                sum-=arr[i];
                i++;
            }
        }
        if(sum==k){
            maxi = max(maxi, j-i+1);
        }
        j++;
    }
    return maxi;
}

int main(){
    int arr[] = {4, 1, 1, 1, 2, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=5;
    
    cout << largSub(arr, n, k);
    return 0;
}
