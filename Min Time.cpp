//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  
    long long solve(vector<int> &fruitType, int index, int currPosition, 
                    unordered_map<int, int> &maxLoc, unordered_map<int, int> &minLoc,
                    vector<vector<long long>> &dp, int indication){
                        
        //base case
        if(index == fruitType.size()) return 0;
        
        if(dp[index][indication] != -1){
            return dp[index][indication];
        }
        
        // Step 1:
        // Now we have two options to move to collect curr type of fruit
        // option1 -> left then right
        // option2 -> right then left
        
        long long option1 = 0;
        long long option2 = 0;
        
        int left = minLoc[fruitType[index]];
        int right = maxLoc[fruitType[index]];
        
        // Step 2:
        // if we chose option 1 -> left then right then we are at position right
        option1 = abs(currPosition - left) + abs(left - right) + solve(fruitType, index+1, right, minLoc, maxLoc, dp, 1);
        // if it is the last fruit type then we have to go to 0th poition
        if(index == fruitType.size() - 1){
            option1 += abs(right);
        }
        
        //similarly for option 2
        option2 = abs(currPosition - right) + abs(right - left) + solve(fruitType, index+1, left, minLoc, maxLoc, dp, 0);
        if(index == fruitType.size() - 1){
            option2 += abs(left);
        }
        
        //step 3:
        return dp[index][indication] = min(option1, option2);
        
    }
  
    long long minTime(int n, vector<int> &locations, vector<int> &types) {

        // step 1: finding max types of a fruit
        int maxi = *max_element(types.begin(), types.end());
        
        // step 2: creating an array of size maxi to store all the types of fruits
                    //also stroing max and min location af curr type 
        
        unordered_map<int, int> maxLoc;
        unordered_map<int, int> minLoc;
        
        vector<int> tempFruitTypes(maxi+1, 0);
        
        for(int i = 0; i<n; i++){
            
            tempFruitTypes[types[i]] = 1;
            
            // if curr type occurs first time
            if(maxLoc.find(types[i]) == maxLoc.end()){
                minLoc[types[i]] = locations[i];
                maxLoc[types[i]] = locations[i];
            }
            else{
                minLoc[types[i]] = min(minLoc[types[i]], locations[i]);
                maxLoc[types[i]] = max(maxLoc[types[i]], locations[i]);
            }
        }
        
        // step 3: Now in tempFruitTypes array we have all the types of fruit 
                  // but there may be some missing types of fruits so making then congiguis in seperate array
        vector<int> fruitType;
        for(int i = 0; i<= maxi; i++){
            if(tempFruitTypes[i] == 1){
                fruitType.push_back(i);
            }
        }
        
        // step 4: finding ans
        int index = 0;
        int currPosition = 0;
        int indication = 0; // which side to move 0->left, 1->right
        
        vector<vector<long long>> dp(fruitType.size() + 1, vector<long long> (2, -1));
        return solve(fruitType, index, currPosition, minLoc, maxLoc, dp, indication);
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
