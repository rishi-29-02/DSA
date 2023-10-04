// Trapping Rainware Problem 

int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> left, right;
        left.push_back(height[0]);
        right.push_back(height[n-1]);
        
        for(int i=1;i<n;i++){
            if(left.back()>height[i]){
                left.push_back(left.back());
            }
            else{
                left.push_back(height[i]);
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(right.back()>height[i]){
                right.push_back(right.back());
            }
            else{
                right.push_back(height[i]);
            }
        }
        
        reverse(right.begin(), right.end());
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans+=min(left[i], right[i]) - height[i];
        }
        
        return ans;
    }
