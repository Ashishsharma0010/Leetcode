class Solution {
public:
    bool canBeEqual(string s1, string s2) {
      string a="";
     string b="";
     a=a+s1[0];
     a=a+s1[2];
     b=b+s2[0];
     b=b+s2[2];
     sort(a.begin(),a.end());
     sort(b.begin(),b.end());
     string c = "";
        string d = "";
        
        c += s1[1];
        c += s1[3];
        
        d += s2[1];
        d += s2[3];
        
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        
        return (a == b && c == d);
    

        
    }
};