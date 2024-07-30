class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>vec;

        for(int i = 0; i <asteroids.size(); i++)
        {
            if(asteroids[i] > 0 )
                vec.push_back(asteroids[i]);
            else
            {
                if(vec.empty() || (!vec.empty() && vec[vec.size()-1] < 0))
                    vec.push_back(asteroids[i]);
                else
                {
                    bool neg = false;
                    while(!vec.empty())
                    {
                        cout<<vec.back()<<" in "<<asteroids[i]<<endl;
                        if(vec.back() > 0 && vec.back() < abs(asteroids[i]))
                        {    
                            vec.pop_back();
                            neg = true;
                        }
                        else if(vec.back() > 0 && vec.back() == abs(asteroids[i]))
                        {
                            vec.pop_back();
                            neg = false;
                            break;
                        }
                        else if(vec.back() > 0 && vec.back() > abs(asteroids[i]))
                        {
                            neg = false;
                            break;
                        }
                        else 
                            break;
                    }

                    if(neg)
                        vec.push_back(asteroids[i]);
                }
                
            }
        }

        return vec;
    }
};