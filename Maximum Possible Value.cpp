class Solution {
  public:
    long long maxPossibleValue(int n,vector<int> a, vector<int> b) {
        // code here
        long long cnt=0,ans=0,mn=1e9+5;
        int i;
        
        for (i=0; i<n; i++){
            int curr=b[i]/2;
            ans+=(2*curr*a[i]);
            if (curr){
               mn=min((int)mn,a[i]);
            }
            
            cnt+=curr;
        }
        
        if (cnt%2){
           ans-=(2*mn); 
        }
        
     return ans;
    }
};
