class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        }
    };

    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
        long long sum = 0, i = 0, j = costs.size()-1;

        for(int indx = 0; indx <candidates; indx++)
        {
            if(i <= j)
            {
                minHeap.push({costs[i], i});
                i++;
            }

            if(i <= j)
            {
                minHeap.push({costs[j], j});
                j--;
            }  
        }
        
        while(k-- && !minHeap.empty())
        {
            pair<int,int> cost = minHeap.top();
            minHeap.pop();
            sum+= cost.first;

            if(cost.second < i && i <= j)
            {
                minHeap.push({costs[i], i});
                i++;
            }
            else if(cost.second > j && i <= j)
            {
                minHeap.push({costs[j], j});
                j--;
            }
        }
        return sum;
    }
};