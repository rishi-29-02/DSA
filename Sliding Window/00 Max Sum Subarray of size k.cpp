// Maximum Sum subarray of size k

long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long i=0, j=0;
        long maxsum = 0;
        long sum=0;
        
        while(j<n){
            sum+=arr[j];
            
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                maxsum = max(sum, maxsum);
                sum-=arr[i];
                i++;j++;
            }
        }
        return maxsum;
    }
