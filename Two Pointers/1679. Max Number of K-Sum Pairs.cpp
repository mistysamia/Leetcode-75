/*********************
 * Using Map
 *********************/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int>mp;
        int cnt = 0;

        for(auto num : nums)
            mp[num]++;
        
        for(auto num : nums)
        {
            if((mp[k - num] > 0 && mp[num] > 0 && num != k-num) || (num == k - num && mp[num] > 1))
            {
                cout<<num<<" "<<k - num<<endl;
                cnt++;
                mp[k - num]--;
                mp[num]--;
            }
        }

        return cnt;
    }
};

/*********************
 * Using Two Pointer
 *********************/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0, i = 0, n = nums.size() - 1;
        sort(nums.begin(), nums.end());
        
        while(i < n)
        {
            if(nums[i] + nums[n] == k)
                cnt++, i++, n--;
            else if(nums[i] + nums[n] < k)
                i++;
            else
                n--;
        }

        return cnt;
    }
};