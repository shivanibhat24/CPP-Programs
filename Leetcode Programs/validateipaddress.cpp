class Solution {
public:
    string validIPAddress(string s) {
        bool ip4 = true, ip6 = true;
        string s1 = "";
        int n = 0, i = 0, c = 0, d = 0, seg = 0;
        for(i = 0; i < s.size(); i++) 
            if(s[i] == '.') c++;
            else if(s[i] == ':') d++;        
        if(c == 3) {
            for(i = 0; i < s.size(); i++) {   
                if(s[i] != '.' && !(s[i] >= '0' && s[i] <= '9')) { ip4 = false; break; }
                if(s[i] != '.') s1 += s[i];
                if(s[i] == '.' || i == s.size() - 1) {
                    if(s1.empty() || (s1.size() > 1 && s1[0] == '0') || s1.size() > 3) { ip4 = false; break; }
                    n = atoi(s1.c_str());
                    if(n > 255) { ip4 = false; break; }
                    s1 = "";
                    seg++;
                }
            }
            if(seg != 4 || s[s.size()-1] == '.') ip4 = false;
        } else ip4 = false;         
        if(d == 7) {
            s1 = "";
            seg = 0;
            for(i = 0; i < s.size(); i++) {   
                if(s[i] != ':' && !((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))) { ip6 = false; break; }
                if(s[i] != ':') s1 += s[i];
                if(s[i] == ':' || i == s.size() - 1) {
                    if(s1.empty() || s1.size() > 4) { ip6 = false; break; }
                    s1 = "";
                    seg++;
                }
            }
            if(seg != 8 || s[s.size()-1] == ':') ip6 = false;
        } else ip6 = false;         
        return ip4 ? "IPv4" : ip6 ? "IPv6" : "Neither";
    }
};
