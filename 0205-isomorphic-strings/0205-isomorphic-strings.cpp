class Solution {
public:
// we have used both set and map ,map is used for mapping the values and set is used for taking repetitions. Try solving it by just using map,you will realise the need of set

    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,char>mp;
        unordered_set<char>s1;
        for(int i=0;i<s.length();i++)
        {
            char x=s[i];
            char y=t[i];
            if(mp.find(x)!=mp.end())
            {
                if(mp[x]!=y)
                    return false;
                else
                    continue;
            }
            else{
            if(s1.find(y)!=s1.end())
                return false;
            mp[x]=y;
            s1.insert(y);
        }}
        return true;
    }
};