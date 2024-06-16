//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    vector<int> getPrimes(int n) {
        if (n <= 3) {
            return {-1, -1};
        }

        // Step 1: Generate all prime numbers up to n using the Sieve of Eratosthenes
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= n; ++p) {
            if (isPrime[p]) {
                for (int multiple = p * p; multiple <= n; multiple += p) {
                    isPrime[multiple] = false;
                }
            }
        }

        // Step 2: Create a list of all prime numbers up to n
        vector<int> primes;
        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        // Step 3: Use the two-pointer approach to find the pair of primes that sum up to n
        int i = 0, j = primes.size() - 1;
        while (i <= j) {
            int sum = primes[i] + primes[j];
            if (sum == n) {
                return {primes[i], primes[j]};
            } else if (sum < n) {
                ++i;
            } else {
                --j;
            }
        }

        return {-1, -1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends
