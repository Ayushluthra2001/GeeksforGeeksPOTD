class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int ans = 0;
        int l = 0 , r = height.size()-1;
        while(l < r){
            int length = r-l-1;
            int h = min(height[l],height[r]);
            int area = length * h;
            ans = max(ans, area);
            if(height[l] < height[r]) l++;
            else r--;
        }
        
        return ans;
        
    }
};
