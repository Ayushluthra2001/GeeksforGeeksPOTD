struct alphanumeric {
    string name;
    int count;
    alphanumeric(string Name, int Count){
        name = Name;
        count = Count;
    }
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        map<string, int> mp;
        for(auto &e : A){
            mp[e]++;
        }
        vector<alphanumeric> ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(alphanumeric(it->first, it->second));
        }
        return ans;
    }
};
