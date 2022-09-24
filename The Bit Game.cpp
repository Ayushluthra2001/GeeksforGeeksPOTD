class Solution{   
public:
    int swapBitGame(long long N){
        
        int countOne=0;
        while(N>0){
            if(N%2==1) countOne++;
            N=N/2;
        }
        if(countOne%2==0) return 2;
        return 1;
        
    }
};
// if there is even no of set bit in N so Player b will win otherwise player a will win 
