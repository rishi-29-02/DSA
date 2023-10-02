// Check if the pair with the given sum exists in the given array 

// Input: arr[] = {0, -1, 2, -3, 1}, x= -2
// Output: Yes
// Explanation:  If we calculate the sum of the output,1 + (-3) = -2

#include <bits/stdc++.h>
using namespace std;

// Brute Force O(n^2)
bool twoLoops(int arr[], int n, int x){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==x){
                return true;
            }
        }
    }
    return false;
}

// Optimized O(n*log(n))
bool twoPointers(int arr[], int n, int x){
    int i=0;
    int j = n-1;
    
    sort(arr, arr+n);
    
    while(i<j){
        int sum = arr[i]+arr[j];
        if(sum == x){
            return true;
        }
        else if(sum<x){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

// Best Solution O(n) O(n)
bool hashmap(int arr[], int n, int x){
    unordered_set<int> s;
    
    for(int i=0;i<n;i++){
        if(s.find(x-arr[i])!=s.end()){
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}

int main(){
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int x=-2;
    
    // Brute Force O(n^2)
    cout << twoLoops(arr, n, x);
    
    // Optimized O(n*log(n))
    cout << twoPointers(arr, n, x);
    
    // Best Solution O(n) O(n)
    cout << hashmap(arr, n, x);
    
    return 0;
}
