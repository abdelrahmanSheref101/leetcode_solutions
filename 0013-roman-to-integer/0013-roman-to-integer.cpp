class Solution {
public:
        //M = 1000, CM = 900, XC = 90 and IV = 4.
    int romanToInt(string s) {
        int value { };
        map<char,int>mp;
        stack<int>stk;
        mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int i=0,ssize=s.size();
        while(i<ssize){
            int curVal=mp[s[i]];
            if(i!=ssize-1){
                int nextVal=mp[s[i+1]];
                if(curVal>=nextVal)
                    value+=curVal,++i;
                else if(curVal<nextVal)
                    value+=(nextVal-curVal),i+=2;

            }
            else
                value+=curVal,++i;
        }
        
        return value;
    }
};