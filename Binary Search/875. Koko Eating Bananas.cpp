class Solution {
public:
    bool allEat(int k ,vector<int>& piles, int h)
    {
        long long int totalHour = 0;

        for(int i = 0; i < piles.size(); i++)
        {
            if(piles[i] % k != 0)
                totalHour+= (piles[i] / k) + 1;
            else
                totalHour+= piles[i] / k;
        }

        if(h < totalHour)
            return false;
        else
            return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1, right = *max_element(piles.begin(), piles.end());

        while(left <= right)
        {
            int mid = (left + right) / 2;

            if( allEat(mid, piles, h) )
                right = mid - 1;
            else
                left = mid + 1;
        }     

        return right + 1;
    }
};