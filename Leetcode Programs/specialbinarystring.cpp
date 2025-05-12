class Solution {
public:
    string solve(string s)
    {
        if (s.empty())
        {
            return "";
        }

        int bal = 0;
        int i=0;

        vector<string> ans;

        for (int j=i;j<s.length();++j)
        {
            if (s[j]=='1')
            {
                bal++;
            }
            else
            {
                bal--;
            }

            if (bal==0)
            {
                ans.push_back("1" + solve(s.substr(i+1,j-i-1))+ "0");
                i=j+1;
            }
        }

        string s1("");
        sort(ans.rbegin(),ans.rend());
        for (size_t i=0;i<ans.size();++i)
        {
            s1+=ans[i];
        }

        return s1;
    }

    string makeLargestSpecial(string s) 
    {
        return solve(s);
    }
};
