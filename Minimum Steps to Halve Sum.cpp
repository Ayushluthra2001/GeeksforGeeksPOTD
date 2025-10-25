class Solution {
public:
    int minOperations(vector<int>& arr) {
        int totalOperation = 0;
        double sum = 0;
        priority_queue<double> pq;
        
        for(int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);  
            sum += arr[i];
        }
        
        double target = sum / 2.0;
        double currSum = sum;
        
        while(currSum > target && !pq.empty()) {
            double curr = pq.top();
            pq.pop();
            
            // Halve the largest element
            double newVal = curr / 2.0;
            currSum = currSum - curr + newVal; // Correct sum update
            
            pq.push(newVal);
            totalOperation++;
        }
        
        return totalOperation;
    }
};
