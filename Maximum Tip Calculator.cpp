//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // Step 1: Prepare the differences array
        vector<pair<int, pair<int, int>>> differences;
        for (int i = 0; i < n; i++) {
            int val = arr[i] - brr[i];
            differences.push_back({val, {arr[i], brr[i]}});
        }
        
        // Step 2: Sort the differences array
        sort(differences.begin(), differences.end());
        
        // Step 3: Calculate the maximum tip
        long long sum = calculateMaxTip(x, y, differences);
        
        return sum;
    }

private:
    long long calculateMaxTip(int x, int y, vector<pair<int, pair<int, int>>>& differences) {
        long long sum = 0;
        int j = differences.size() - 1;
        
        // Choosing the positive differences first with limit x
        while (x > 0 && j >= 0 && differences[j].first >= 0) {
            sum += differences[j].second.first;
            x--;
            j--;
        }
        
        int i = 0;
        // Choosing the negative differences with limit y
        while (y > 0 && i <= j && differences[i].first <= 0) {
            sum += differences[i].second.second;
            y--;
            i++;
        }
        
        // Choosing remaining x
        while (x > 0 && j >= i) {
            sum += differences[j].second.first;
            x--;
            j--;
        }
        
        // Choosing remaining y
        while (y > 0 && i <= j) {
            sum += differences[i].second.second;
            y--;
            i++;
        }
        
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends
