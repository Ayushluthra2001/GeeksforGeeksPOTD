  long long result=0;
        for(int i=0;i<32;i++){
            long long countOne=0;
            long long countZeros=0;
            for(int j=0;j<n;j++){
                if(arr[j] & (1<<i))
                    countOne++;
               else
                    countZeros++;
            }
            result+=countOne*(countZeros)*2;
        }
        return result;
