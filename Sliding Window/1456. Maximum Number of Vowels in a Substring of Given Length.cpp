class Solution {
public:

    bool isVowel(char c) 
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int maxVowels(string s, int k) {
        int indx = 0, mx = 0, cnt = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(k > i)
            {
                if(isVowel(s[i]))
                    cnt++;
                mx = max(mx, cnt);
            }
            else
            {
                if(isVowel(s[indx++]))
                    cnt--;
                
                if(isVowel(s[i]))
                    cnt++;
                
                mx = max(mx, cnt);
            }
        }

        return mx;
    }
};