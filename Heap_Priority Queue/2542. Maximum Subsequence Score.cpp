class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>> pq;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, mx = 0;

        for(int i = 0; i < nums1.size() ; i++)
            pq.push({nums2[i],nums1[i]});

        while(!pq.empty())
        {
            sum += pq.top().second;
            minHeap.push(pq.top().second);

            if (minHeap.size() > k) 
            {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k) 
                mx = max(mx, sum * pq.top().first);
            
            pq.pop();
        }

        return mx;
    }
};