class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int a = 0, b = -1, mx = 0;
        bool zero = false;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                if(!zero)
                {
                    b = i + 1;
                    zero = true;
                    mx = max(mx, i - 1 - a);
                }
                else
                {
                    mx = max(mx, i - 1 - a);
                    a = b;
                    b = i + 1;
                }
            }
            else if(nums.size()-1 == i && zero)
                mx = max(mx, i - a);
        }

        return ( b == -1 || !zero ) ? nums.size() - 1 : mx;
    }
};