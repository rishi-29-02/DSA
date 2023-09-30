// Selection Sort 

// a. It is in-place sorting i.e. takes constant space.
// b. Time Complexity :: O(n^2)
// c. Space Complexity :: O(1)
// d. It is an unstable sorting i.e. doesn't maintains the order of the appearing element

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0;i<n;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main(){
    int arr[] = {4, 2, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    selectionSort(arr, n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
