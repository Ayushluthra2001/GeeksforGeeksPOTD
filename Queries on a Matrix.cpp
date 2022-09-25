
class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {

        

        vector<vector<int>> ans(n,vector<int>(n,0));

        

        for(auto t:  Queries){

            int a=t[0] ;

            int b=t[1] ;

            int c=t[2] ;

            int d=t[3] ;

            for(int j=a;j<=c;j++){

                for(int k=b;k<=d;k++){

                    ans[j][k]++;

                }

            }

        }

        return ans;

    }
};
