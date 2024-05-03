class Solution{
    public:

    bool isPalindrome(string s) {
        string str;
        for(auto &chr:s){
            char tmp=tolower(chr);
            if(('a'<=tmp&&tmp<='z')||isdigit(tmp))
                str.push_back(tmp);
        }
        for(int front=0,rear=str.size()-1;front<rear;++front,--rear){
                if(str[front]!=str[rear])
                    return false;
        }
        return true;

    }
};