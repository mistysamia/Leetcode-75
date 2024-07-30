class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = INT_MIN, i = 0, n = height.size() - 1;

        while (i < n) 
        {
            mx = max(mx, min(height[i], height[n]) * (n - i));
            if (height[i] < height[n])
                i++;
            else 
                n--;
        }

        return mx;
    }
};