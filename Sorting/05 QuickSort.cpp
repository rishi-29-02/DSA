// Quick Sort 

// a. It is an in-place sorting 
// b. Time Complexity :: O(n*Log(n))
// c. Space Complexity :: O(n)
// d. It is an unstable sorting i.e. doesn't maintains the order of the appearing element
// e. Worst Case :: O(n^2), when the array is already sorted

// Lumoto ( LeftMost is the Pivot) and Horare's ( RightMost is the Pivot) Partition 

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int st, int end){
    int pi = arr[end];
    int i=st-1;
    
    for(int j=st;j<end;j++){
        if(arr[j]<pi){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[end]);
    return i+1;
}

void quickSort(int arr[], int st, int end){
    if(st<end){
        int pi = partition(arr, st, end);
        
        quickSort(arr, st, pi-1);
        quickSort(arr, pi+1, end);
    }
}

int main(){
    int arr[] = {5, 1, 3, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    quickSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
