// First negative number in each subarray of size k 

#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegative(int arr[], int n, int k){
    vector<int> v;
    int i=0, j=0;
    queue<int> q;
    while(j<n){
        if(arr[j]<0) q.push(arr[j]);
        
        if((j-i+1)==k){
            if(q.empty()){
                v.push_back(0);
            } else {
                v.push_back(q.front());
                if(arr[i]==q.front()){
                    q.pop();
                }
            }
            i++;j++;
        } else {
            j++;
        }
    }
    return v;
}

int main(){
    int arr[] = {4, -3, 1, 6, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    
    vector<int> v = firstNegative(arr, n, k);
    for(auto it:v){
        cout << it << " ";
    }
    return 0;
}
