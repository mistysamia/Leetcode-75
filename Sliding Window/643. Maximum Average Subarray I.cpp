class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        long long sum = 0;

        for(int i = 0; i < k; i++)
            sum+= nums[i];

        avg = (double) sum / (double)k;
        for(int i = k; i < nums.size(); i++)
        {
            sum-= nums[i - k];
            sum+= nums[i];

            avg = max(avg, (double) sum / (double)k);
        }

        return avg;
    }
};