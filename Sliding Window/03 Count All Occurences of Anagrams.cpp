// Count All Occurences of Anagrams

int search(string pat, string s) {
	    // code here
	    int n = s.size();
	    int k=pat.size();
	    
	    int i=0,j=0;
	    
	    unordered_map<char, int> mp;
	    for(int i=0;i<k;i++){
	        mp[pat[i]]++;
	    }
	    
	    int cnt = mp.size();
	    int ans=0;
	    
	    while(j<n){
	        if(mp.find(s[j])!=mp.end()){
	            mp[s[j]]--;
	            if(mp[s[j]]==0){
	                cnt--;
	            }
	        }
	        
	        if(j-i+1<k){
	            j++;
	        }
	        else if(j-i+1==k){
	            if(cnt==0){
	                ans++;
	            }
	            
	            if(mp.find(s[i])!=mp.end()){
	                mp[s[i]]++;
	                if(mp[s[i]]==1){
	                    cnt++;
	                }
	            }
	            i++;j++;
	        }
	    }
	    
	    return ans;
	}
