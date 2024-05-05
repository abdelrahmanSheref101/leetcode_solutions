class Solution {
public:
       bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int charMap[150]= { };   
        for (auto &chr:s)
            charMap[chr]++;
        for (auto &chr:t){
            if(!charMap[chr]--)
                return false;
        }
        return true;
    }
};