class Solution {
public:
    int indxFind(vector<int>& potions, long long success, int value)
    {
        long long left = 0 , right = potions.size() - 1;

        while(left <= right)
        {
            long long mid = (left + right) / 2;
            if( (long long)value * potions[mid] >= success)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return right + 1;
    }


    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> vec;
        sort(potions.begin(), potions.end());
        
        for(int i = 0; i < spells.size(); i++)
        {
            int indx = indxFind(potions, success, spells[i]);
            vec.push_back(potions.size() - indx);
        } 

        return vec;
    }
};