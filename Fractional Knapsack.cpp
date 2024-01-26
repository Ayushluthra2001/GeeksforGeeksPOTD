//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
   
    static bool compare(Item a,Item b){
        double f1=(double) a.value/a.weight;
        double f2=(double) b.value/b.weight;
        return f1>f2;
    }
    
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr,arr+n,compare);
        double ans=0;
        for(int i=0;i<n;i++){
            int val=arr[i].value;
            int wei=arr[i].weight;
            if(wei<w){
                ans+=(double)val;
                w-=wei;
            }
            else{
                ans+=(double)  val/wei *w;
                w=0;
                break;
            }
        }
        
        
        return ans;
        
    }
        
};
    
        

//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
