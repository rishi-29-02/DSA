// Binary Search 

// Time Complexity :: O(log(n))

#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int st, int end, int k){
    int mid = st + (end-st)/2;
    
    if(st<=end){
        if(arr[mid]==k){
            return true;
        }
        else if(arr[mid]<k){
            return binarySearch(arr, mid+1, end, k);
        }
        else if(arr[mid]>k){
            return binarySearch(arr, st, mid-1, k);
        }    
    }
    else{
        return false;
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int k=2;
    cout << binarySearch(arr, 0, n-1, k);
    return 0;
}
