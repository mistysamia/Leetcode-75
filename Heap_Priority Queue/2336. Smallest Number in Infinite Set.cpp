class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int,int>mp;
    int mx = 1;

    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000 ; i++)
        {    
            mp[i] = 1;
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int val;
        if(!pq.empty())
        {
            val = pq.top();
            mp[val] = 0;
            pq.pop();
        }
        return val;
    }
    
    void addBack(int num) {
        if(mp[num] == 0)
        {    
            pq.push(num);
            mp[num] = 1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */