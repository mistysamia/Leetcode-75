class Solution {
public:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        if(ch == 'a' || ch == 'e' || ch =='i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }

    string reverseVowels(string s) {
        int i = 0, n = s.size();

        while(i<n)
        {
            while(i<n && !isVowel(s[i]))
                i++;

            while(i<n && !isVowel(s[n]))
                n--;
            
            swap(s[i],s[n]);
            i++, n--;
        }

        return s;
    }
};