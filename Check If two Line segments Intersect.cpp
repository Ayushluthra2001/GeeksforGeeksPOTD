//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   string doIntersect(int p1[], int p2[], int q1[], int q2[]) { 
        
        double m1=(p2[1]-p1[1])/double(p2[0]-p1[0]); 
        double m2=(q2[1]-q1[1])/double(q2[0]-q1[0]); 
        double v11=m1*(p1[0]-q1[0])-(p1[1]-q1[1]); 
        double v12=m1*(p1[0]-q2[0])-(p1[1]-q2[1]); 
        double v21=m2*(q1[0]-p1[0])-(q1[1]-p1[1]); 
        double v22=m2*(q1[0]-p2[0])-(q1[1]-p2[1]); 
        // cout<<v11<<' '<<v12<<' '<<v21<<' '<<v22<<endl; 
        if(v11*v12>0 || v21*v22>0)return "false"; 
        return "true"; 
    } 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends
