class Solution {
public:
int lengthOfLastWord(string s) {
        istringstream iss(s);
        string wrd;
        while(iss>>wrd){}
        return wrd.size();
    }
};