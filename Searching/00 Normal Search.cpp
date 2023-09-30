// Normal Search

// Time Complexity O(n)

#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    
    bool flag = false;
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            flag = true;
            break;
        }
    }
    
    cout << flag;
    return 0;
}
