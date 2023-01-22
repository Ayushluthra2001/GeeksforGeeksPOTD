class Solution {
  public:
    int solve(int N, int K, vector<int> &arr) {
        // code here
        // make a prefix array
        for(int i = 1;i<N;i++){
            arr[i] += arr[i-1];
        }
        // converting array to prefix sum array
        vector<int> divisors;
        int sum = arr[N-1];
        for(int i = 1;i*i<=sum;i++){
            if(sum%i == 0){
                divisors.push_back(i);
                if(i != sum/i){
                    divisors.push_back(sum/i);
                }
            }
        }
        // finding all the divisors for the solution;
        int ans = 1; // because 1 is universal GCD;
        for(int divisor : divisors){
            int count = 0; // counts possible sums which can be divided for divisor
            for(int i = 0 ;i<N;i++){
                if(arr[i] % divisor == 0)count++;
                if(count>=K){
                    ans = max(ans,divisor);
                }
            }
        }
        return ans;
    }
};
