//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
const int mod=1e9+7;
const int N=1e5+5;

bool f=0;
class Solution {
  public:
    
    ll binpow(ll a,ll b,ll p){
        
        if(b==0)
            return 1;
            
        ll t=binpow(a,b/2,p);
        
        if(b%2)
            return (((a*t)%p)*t)%p;
        else 
            return ((t*t)%p);
    }
     
    ll fact[N],invfact[N];
    
    void init(){
        
        fact[0]=1;
        for(ll i=1;i<N;i++){
            fact[i]=i*fact[i-1]%mod;
        }
        
        invfact[N-1]=binpow(fact[N-1],mod-2,mod);
        
        for(ll i=N-2;i>=0;i--){
            invfact[i]=(i+1)*invfact[i+1]%mod;
        }
        
    }
    
    ll ncr(ll n,ll r,ll p){
        return (((fact[n]*invfact[n-r])%p)*invfact[r]%p)%p;
    }
    
    
    
    int bestNumbers(int n, int A, int B, int C, int D) {
        // code here
        if(!f){
            init();
            f=1;
        }
            
        long long ans=0;
        if(A==B){
            long long sum=(A*n)%mod;
             while(sum>0){
                if(sum%10==C || sum%10==D){
                    return 1;
                }
                sum/=10;
            }
            return 0;
        }
        
        for(int x=0;x<=n;x++){
            long long sum=x*A+(n-x)*B;
            bool flag=0;
            while(sum>0){
                if(sum%10==C || sum%10==D){
                    flag=1;
                    break;
                }
                sum/=10;
            }
            if(flag){
                ans+=ncr(n,x,mod);
                ans%=mod;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
