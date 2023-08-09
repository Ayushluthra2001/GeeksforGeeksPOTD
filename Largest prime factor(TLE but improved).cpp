//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
       
        vector<bool>seive(N+1,true);
        for(long long int i=2;i<=sqrt(N);i++){
            if(seive[i]==true){
                for(long long int j=i*2;j<=N;j+=i){
                    seive[j]=false;
                }
            }
        }
        
        // for(int i=0;i<seive.size();i++){
        //     if(seive[i]==true) cout<<i<<"  ";
        // }
        // cout<<endl;
        long long int longest=INT_MIN;
        for(long long int i=N;i>=1;i--){
            if(seive[i]==true){
                if(N%i==0) return i;
            }
        }
        return 1;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
