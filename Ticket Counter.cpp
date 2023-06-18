//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int k) {
        // code here
        int start=1;
        int end=N;
        bool dir=true;
        while((end-start)>=k){
            start+=k;
            dir=!dir;
            if(end-k>=start){
                end-=k;
                dir=!dir;
            }
            
        }
        if(dir==true) return end;
        return start;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
