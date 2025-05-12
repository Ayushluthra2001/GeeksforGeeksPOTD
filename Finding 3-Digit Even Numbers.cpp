class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        unordered_map<int,int>mapping;
        for(int i = 0; i<digits.size();i++){
            for(int j = 0; j<digits.size(); j++){
                for(int k = 0; k<digits.size(); k++){
                    if(i == j || j== k || k== i) continue;

                    int number = digits[i];
                    number = number * 10 + digits[j];
                    number = number * 10 + digits[k];
                    if(number >= 100 && number<=998){
                        if(number % 2==0) mapping[number]++;
                    }
                }
            }
        }
        for(auto i : mapping) ans.push_back(i.first);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
