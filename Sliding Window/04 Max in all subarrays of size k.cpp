// Maximum of all subarrays of size k 

#include <bits/stdc++.h>
using namespace std;

vector<int> maxAllSub(int arr[], int n, int k){
    int i=0, j=0;
    int maxi = INT_MIN;
    
    vector<int> ans;
    deque<int> pq;
    
    while(j<n){
        while(!pq.empty() && pq.back()<arr[j]){
            pq.pop_back();
        }
        pq.push_back(arr[j]);
        
        if(j-i+1==k){
            if(!pq.empty()){
                ans.push_back(pq.front());
                if(arr[i]==pq.front()){
                    pq.pop_front();
                }
            }
            i++;j++;
        } else {
            j++;
        }
    }
    return ans;
}

int main(){
    int arr[] = {1, 4, 2, 7, 5, 6, 3}; // 4 7 7 7 6 
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    
    vector<int> v =  maxAllSub(arr, n, k);
    for(auto it:v){
        cout << it << " ";
    }
    return 0;
}
