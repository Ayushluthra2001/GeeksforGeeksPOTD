//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    bool check(int i , int j, int r, int c){
        if(i<0 || j<0 || i>=r || j>=c) return false;
        return true;
    }
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        unordered_map<char , char > mapping;
        mapping['u']='r';
        mapping['r']='d';
        mapping['d']='l';
        mapping['l']='u';
        int i=0,j=0;
        char prev='r';
        while(true){
            
            if(matrix[i][j]==0){
                
                if(prev=='r'){
                    if(check(i,j+1,R,C)){
                       
                        j=j+1;
                    }else{
                        return {i,j};
                    }
                }else if(prev=='u'){
                    if(check(i-1,j,R,C)){
                        i--;
                    }else{
                        return {i,j};
                    }
                    
                }else if(prev=='l'){
                    if(check(i,j-1,R,C)){
                        j--;
                    }else{
                        return {i,j};
                    }
                }else{
                    if(check(i+1,j,R,C)){
                        i++;
                    }else{
                        return {i,j};
                    }
                }
            }else{
                matrix[i][j]=0;
                prev=mapping[prev];
                if(prev=='r'){
                    if(check(i,j+1,R,C)){
                        j=j+1;
                    }else{
                        return {i,j};
                    }
                }else if(prev=='u'){
                    if(check(i-1,j,R,C)){
                        i--;
                    }else{
                        return {i,j};
                    }
                    
                }else if(prev=='l'){
                    if(check(i,j-1,R,C)){
                        j--;
                    }else{
                        return {i,j};
                    }
                }else{
                    if(check(i+1,j,R,C)){
                        i++;
                    }else{
                        return {i,j};
                    }
                }
            }
        }
        return {0,0};
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends
