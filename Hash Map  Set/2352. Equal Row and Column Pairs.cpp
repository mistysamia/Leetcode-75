class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int>row, col;
        int cnt = 0;

        for(int i = 0; i <grid.size(); i++)
        {
            vector<int>vec;
            for(int j = 0; j<grid[i].size(); j++)
            {
                vec.push_back(grid[i][j]);
                if(j == grid[i].size()-1)
                    row[vec]++;
            }
        }

        for(int i = 0; i <grid[0].size(); i++)
        {
            vector<int>vec;
            for(int j = 0; j<grid.size(); j++)
            {
                vec.push_back(grid[j][i]);
                if(j == grid.size()-1)
                    col[vec]++;
            }
        }

        for(auto it = row.begin(); it!= row.end(); it++)
            if(col.find(it->first) != col.end())
                cnt+= it->second * col[it->first];
        
        return cnt;
    }
};