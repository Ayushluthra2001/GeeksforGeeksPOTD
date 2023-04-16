//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        vector<long long>odd1,odd2,even1,even2;
        long long osum1=0,esum1=0,osum2=0,esum2=0;
        for(int i =0;i<A.size();i++){
            if(A[i]%2 == 0){
                even1.push_back(A[i]);
                esum1=esum1+A[i];
            }else{
                odd1.push_back(A[i]);
                 osum1=osum1+A[i];
            }
            
            if(B[i]%2==0)
            {
                even2.push_back(B[i]);
                esum2=esum2+B[i];
            }else{
                odd2.push_back(B[i]);
                 osum2=osum2+B[i];
            }
        }
        
        
        
       // cout<<esum1<<" "<< esum2<<" "<<osum1<<" "<<osum2<<" "; 
        if(esum1+ osum1!= esum2+osum2) return -1;
        if(even1.size()!= even2.size() || odd1.size()!=odd2.size()) return -1;
        
        long long ans=0;
        sort(odd1.begin(),odd1.end());
        sort(even1.begin(),even1.end());
        sort(odd2.begin(),odd2.end());
        sort(even2.begin(),even2.end());
        for(int i =0;i<odd1.size();i++){
            ans += abs(odd1[i]-odd2[i]);
        }
        for(int i =0;i<even1.size();i++){
            ans += abs(even1[i]-even2[i]);
        }
        return ans/4;
    }

};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
