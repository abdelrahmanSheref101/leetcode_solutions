class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector <string> res; 
       generate(res,n,0,0,"");
       return res;
    }

    private:
    void generate(vector<string>&res,int n,int closeN,int openN,string str){
        if(closeN==n && openN==n){
            res.push_back(str);
            return ;
        }
        if(openN<n){
            generate(res,n,closeN,openN+1,str+"(");
        }
        if(closeN<openN){
            generate(res,n,closeN+1,openN,str+")");
        }
    }
};