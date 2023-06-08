//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
     int cal(int l ,int r , char ch, string str)
     {
         while(l<=r)
         {
             int mid = (l+r)/2 ;
             if(str[mid]<=ch)
             r =mid-1; 
             else
             l =mid+1; 
         }
         if(l<str.length() && str[l]>ch)
         return l ; 
         return r ;
     }


    string kthPermutation(int n, int k)
    {
        // code here
        string str = "" ; 
        for(int  i=1;i<=n; i++ )
        {
            str+= (i+'0'); 
        }
        int len = n ;
        k--;
        while(k--)
        {
            
            for(int i = len-2 ;i>=0;i--)
            {
                if(str[i]<str[i+1])
                {
                    int ind  = cal(i+1 , len-1 , str[i] , str ) ;
                    swap(str[i], str[ind]) ;
                    reverse(str.begin()+i+1 ,str.end()); 
                    break ;
                }
            }
        }
        
        return str ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
