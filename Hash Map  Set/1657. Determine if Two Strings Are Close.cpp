class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>mp1, mp2;

        for(int i = 0; i<word1.size() ; i++)
            mp1[word1[i]]++;
        
        for(int i = 0; i<word2.size() ; i++)
        {
            mp2[word2[i]]++;
            if(mp1.find(word2[i]) == mp1.end())
                return false;
        }

        if(mp1.size() != mp2.size())
            return false;
        
        vector<int> vec1,  vec2;

        for(auto it1 = mp1.begin(), it2 = mp2.begin(); it1 != mp1.end(); it1++, it2++)
        {
            vec1.push_back(it1->second);
            vec2.push_back(it2->second);
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());

        for(int i = 0; i<vec1.size(); i++)
            if(vec1[i] != vec2[i])
                return false;
        
        return true;
    }
};