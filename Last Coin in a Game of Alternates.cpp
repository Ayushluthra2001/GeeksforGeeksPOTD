// one liner code 
class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        return *min_element(arr.begin(),arr.end());
    }
};

// code according to the question instruction 

class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int i = 0 , j = arr.size()-1;
        int player1 = true;
        int player2 = false;
        int value = -1;
        while(i<=j){
            if(player1){
                player1 != player1;
                if(arr[i] >=arr[j]) {
                    value = arr[i];
                    i++;
                }else{
                    value = arr[j];
                    j--;
                }
            }else {
                player2!= player2;
                if(arr[i] >=arr[j]) {
                    value = arr[i];
                    i++;
                }else{
                    value = arr[j];
                    j--;
                }
            }
        }
        return value;
    }
};
