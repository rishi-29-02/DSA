// Insertion Sort 

// a. It is in-place sorting i.e. takes constant space.
// b. Time Complexity :: O(n^2)
// c. Space Complexity :: O(1)
// d. It is a stable sorting i.e. maintains the order of the appearing element

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j-1]>arr[j]){
                swap(arr[j-1], arr[j]);
            }
            else{
                break;
            }
        }
    }
}

int main(){
    int arr[] = {4, 1, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    insertionSort(arr, n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
