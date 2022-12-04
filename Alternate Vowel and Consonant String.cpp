//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string s, int n)

    {

    string ans(n, 'a');

        int arr[26]={0};

        int count=0,odd=0;

        for(int i=0;i<n;i++){

            arr[s[i]-'a']++;

            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i] =='o' || s[i] =='u'){

                count++;

            }else{

                odd++;

            }  

        }int j;int p;

        if(count<odd){

            j=1;

            p=0;

        }else{

            j=0;p=1;

        }

        

        if(abs(count-odd)==0 || abs(count-odd)==1){

            for(int i=0;i<=25;i++){

char ch= char(i+'a');

while(arr[i]>0){

                           if(ch=='a' || ch=='e' || ch=='i' || ch =='o' || ch =='u'){

                          ans[j]=ch;

                          arr[i]--;

                          j=j+2;}

                          else{

                               ans[p]=ch;

                          p=p+2;

                          arr[i]--;  

                          }   

                      }   

                  }

}else{

            return to_string(-1);

        }  return ans;
        }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
