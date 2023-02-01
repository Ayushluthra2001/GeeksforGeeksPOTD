class Solution{   

    #define ll long long

public:

    long long int distinctColoring(int N, int r[], int g[], int b[]){

        // code here 

        vector<vector<ll>> dp(3, vector<ll>(N));

        dp[0][0] = r[0];

        dp[1][0] = g[0];

        dp[2][0] = b[0];

        

        

        for(int i = 1; i < N; i++){

            for(int j = 0; j < 3; j++){

                if(j == 0){

                    dp[j][i] = min(dp[1][i - 1], dp[2][i - 1]) + r[i];

                }else if(j == 1){

                    dp[j][i] = min(dp[0][i - 1], dp[2][i - 1]) + g[i];

                }else if(j == 2){

                    dp[j][i] = min(dp[0][i - 1], dp[1][i - 1]) + b[i];

                }

            }

        }

       

        return min(dp[0][N - 1], min(dp[1][N - 1], dp[2][N - 1]));

    }

};
