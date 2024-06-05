class RecentCounter {
public:
    deque<int>deq;
    RecentCounter() {
        deq.clear();
    }
    
    int ping(int t) {
        deq.push_back(t);
        int sum = 0, duration = t-3000;

        for(int i = deq.size()-1 ; i>=0 ; i--)
        {
            if(deq[i] >= duration)
                sum++;
            else
                break;
        }
        return sum;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */