// Kadene's Algorithm (Largest Sum Contigeous Subarray)

#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int maxsum = 0;
    int currsum = 0;
    
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        if(currsum>maxsum){
            maxsum=currsum;
        }
        if(currsum<0){
            currsum=0;
        }
    }
    cout << maxsum;
    return 0;
}
