class Solution {
public:
    string removeStars(string s) {
        stack<int>stk;
        string ans;

        for(int i = 0; i <s.size() ; i++)
        {
            if(s[i] != '*')
                stk.push(s[i]);
            else
                stk.pop();
        }

        while(!stk.empty())
        {
            ans.insert(0,1,stk.top()); 
            stk.pop();
        }

        return ans;
    }
};