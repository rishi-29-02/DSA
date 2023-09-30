// Merge Sort 

// a. It is out-place sorting 
// b. Time Complexity :: O(n*Log(n))
// c. Space Complexity :: O(n)
// d. It is a stable sorting i.e. maintains the order of the appearing element

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int st, int mid, int end){
    int n = mid-st+1;
    int m = end-mid;
    
    int a[n]; 
    int b[m];
    
    for(int i=0;i<n;i++){
        a[i] = arr[i+st];
    }
    for(int i=0;i<m;i++){
        b[i] = arr[i+mid+1];
    }
    
    int i=0, j=0;
    int k=st;
    
    while(i<n && j<m){
        if(a[i]<b[j]){
            arr[k] = a[i];
            i++;k++;
        }
        else{
            arr[k] = b[j];
            j++;k++;
        }
    }
    
    while(i<n){
        arr[k] = a[i];
        i++;k++;
    }
    
    while(j<m){
        arr[k] = b[j];
        j++;k++;
    }
}

void mergeSort(int arr[], int st, int end){
    if(st<end){
        int mid = st + (end-st)/2;
        
        mergeSort(arr, st, mid);
        mergeSort(arr, mid+1, end);
        
        merge(arr, st, mid, end);
    }
}

int main(){
    int arr[] = {4, 2, 3, 1, 6, 9, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    mergeSort(arr, 0, n-1);
    
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
