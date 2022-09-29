#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int countOne=0;
        int countTwo=0;
        int countZero=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                countZero++;
            }else if(a[i]==1) 
            countOne++;
            else 
            countTwo++;
        }
        for(int i=0;i<n;i++){
            if(countZero>0){
                countZero--;
                a[i]=0;
            }else if(countOne>0){
                countOne--;
                a[i]=1;
            }else{
                a[i]=2;
            }
        }
    }
    
};
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}
