class Solution {
public:
    string binaryBits(int n)
    {
        string s;
        while(n>0)
        {
            s+= to_string(n%2);
            n/=2;
        }
        reverse(s.begin(), s.end());
        return s;
    }


    void binaryBits(string& s, int n)
    {
        while(n--)
            s.insert(0,1,'0');
    }

    int minFlips(int a, int b, int c) {
        string str_a = "", str_b = "" , str_c = "";

        str_a = binaryBits(a);
        str_b = binaryBits(b);
        str_c = binaryBits(c);
        
        int mx_len = max(str_a.size() , max(str_b.size() , str_c.size()));
        binaryBits(str_a, mx_len - str_a.size());
        binaryBits(str_b, mx_len - str_b.size());
        binaryBits(str_c, mx_len - str_c.size());
        
        int cnt = 0;
        
        for(int i = str_a.size()-1 ; i>=0 ; i--)
        {
            if(str_a[i] == '0' && str_b[i] == '0' && str_c[i] == '1')
                cnt++;
            if(str_c[i] == '0' && str_a[i] == '1')
                cnt++;
            if(str_c[i] == '0' && str_b[i] == '1')
                cnt++;
        }
        
        return cnt;
    }
};