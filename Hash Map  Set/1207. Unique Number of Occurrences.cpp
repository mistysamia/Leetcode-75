class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp1,mp2;

        for(int i = 0; i < arr.size(); i++)
            mp1[arr[i]]++;
        
        for(auto it = mp1.begin(); it!=mp1.end(); it++)
        {
            if(mp2.find(it->second) != mp2.end())
                return false;

            mp2[it->second]++;
        }
        
        return true;
    }
};