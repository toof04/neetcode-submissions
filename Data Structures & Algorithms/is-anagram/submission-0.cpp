class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>m(26,0);
        vector<int>m2(26,0);
        if(s.length()!=t.length())return false;
        for(int i = 0;i<s.length();i++){
            char chara = s[i];
            char chart = t[i];
            m[chara-'a']++;
            m2[chart-'a']++;
        }
        for(int i = 0;i<26;i++){
            if(m[i]!=m2[i])return false;
        }
        return true;

    }

};
