class Solution {
public:

    void backtrack(int k , int n, int num, int sum, vector<int>& vec, vector<vector<int>>& ans)
    {
        if(sum > n || num > 10)
            return;
        
        if(sum == n && vec.size() == k)
            ans.push_back(vec);

        for(int i = num; i<10 ; i++)
        {
            vec.push_back(i);
            backtrack(k , n, i+1 , sum + i, vec, ans);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>vec;
        vector<vector<int>>ans;

        backtrack(k , n, 1 , 0, vec, ans);
        return ans;
    }
};