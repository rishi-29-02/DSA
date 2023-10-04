// Find the first negative integer in each subarray of size k

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
                                                 long long int i=0, j=0;
                                                 vector<long long> ans;
                                                 deque<long long> nlist;
                                                 
                                                 while(j<n){
                                                     if(arr[j]<0){
                                                         nlist.push_back(arr[j]);
                                                     }
                                                     
                                                     if(j-i+1<k){
                                                         j++;
                                                     }
                                                     else if(j-i+1==k){
                                                         if(nlist.size()==0){
                                                             ans.push_back(0);
                                                         }
                                                         else{
                                                             ans.push_back(nlist.front());
                                                             if(arr[i]==nlist.front()){
                                                                 nlist.pop_front();
                                                             }
                                                         }
                                                         i++;j++;
                                                     }
                                                 }
                                                 return ans;
 }
