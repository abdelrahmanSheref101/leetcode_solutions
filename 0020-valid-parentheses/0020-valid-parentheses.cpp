class Solution {
public:
    bool isValid(string s) {
        map<char,char>mp;
        mp['}']='{';
        mp[']']='[';
        mp[')']='(';
        stack<char> stk;
        for(auto & elm:s){
            
            if(elm=='}'||elm==']'||elm==')'){
                if(stk.empty()||mp[elm]!= stk.top())
                    return false;
                else
                    stk.pop();
            }
            else
                stk.push(elm);
        }
        return stk.empty();
    }
};