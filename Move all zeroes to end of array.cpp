//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    vector<int>temp;
	    int countZero=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]!=0)
	        temp.push_back(arr[i]);
	        else countZero++;
	        
	    }
	    for(int i=0;i<n;i++){
	        if(i<temp.size()){
	            arr[i]=temp[i];
	        }else arr[i]=0;
	    }
	    
	}
};
