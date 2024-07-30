class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int inc = 0 , val ;

        for(int i = nums.size()-1; i >= 0; i--)
        {
            inc++;
            if(inc == k)
                return nums[i];
        }

        return val;
    }
};