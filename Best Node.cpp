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
    long long bestNode(int N, vector<int> &A, vector<int> &P) {

        

        //Step-1 ..Create a set and push P array into set

        set<int> s;

        for(int i=0;i<N;i++)

        {

            s.insert(P[i]);

        }

        

        //Step-2 ..Find out leaf nodes from s 

        vector<int> leaf_node;

        for(int i=1;i<=P.size();i++)

        {

            if(!s.count(i))

            {

                leaf_node.push_back(i);

            }

        }

        

        //Step-3 ..Traverse from leaf to root and store max at each and every time visited new node

        long long ans = LLONG_MIN;

        for(int leaf : leaf_node)

        {

            int curr_node = leaf;

            long long sum = 0;

            

            //-1 indicate the root

            while(curr_node!=-1)

            {

                sum = -sum;

                sum+=A[curr_node-1];

                

                ans = max(ans,sum);

                curr_node = P[curr_node-1];

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
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
