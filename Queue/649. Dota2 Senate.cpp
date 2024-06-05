class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<int>rad, dire;

        for(int i = 0; i<senate.size(); i++)
        {
            if(senate[i] == 'D')
                dire.push_back(i);
            else
                rad.push_back(i);
        }

        while(!rad.empty() && !dire.empty())
        {
            int indx_D = dire.front();
            int indx_R = rad.front();
            dire.pop_front();
            rad.pop_front();

            if(indx_D < indx_R)
                dire.push_back(indx_D + senate.size());
            else
                rad.push_back(indx_R + senate.size());
        }
        
        return dire.empty() ? "Radiant" : "Dire";
    }
};