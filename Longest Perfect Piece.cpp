int longestPerfectPiece(int arr[], int n) {
        // code here
        map<int,int> mp;
        int ans=1;
        int l=0;
        for(int r=0;r<n;r++){
            mp[arr[r]]++;
            //cout<<mp.rbegin()->first<<" "<<mp.begin()->first<<endl;
            while(mp.rbegin()->first-mp.begin()->first>1){
                mp[arr[l]]--;
                if(mp[arr[l]]==0){
                    mp.erase(arr[l]);
                }
                l++;
            }
            
            ans=max(ans,r-l+1);
        }
        return ans;
    }
