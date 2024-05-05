class Solution {
public:
    bool isPalindrome (string &str){
        if(str.size()==2)
            return (str[0]==str[1]);
        int firstPos=0,lastPos=str.size()-1;
        while(firstPos<lastPos){
           if(str[firstPos++]!=str[lastPos--]) 
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto &word:words)
            if(isPalindrome(word))
                return word;
        return "";
    }
};