// Bubble Sort 

// The Idea is swapping the Adjacent elements

#include <bits/stdc++.h>
using namespace std;

void bubleSort(int arr[], int n){
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(!flag){
            break;
        }
    }
}

int main(){
    int arr[] = {4, 2, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bubleSort(arr, n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
    
}

// a. It is in-place sorting i.e. takes constant space.
// b. Time Complexity :: O(n^2)
// c. Space Complexity :: O(1)
// d. It is a stable sorting i.e. maintains the order of the appearing element
